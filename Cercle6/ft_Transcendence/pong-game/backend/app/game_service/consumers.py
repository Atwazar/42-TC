import os
import jwt
import logging
from dotenv import load_dotenv
import json
import uuid
import asyncio
from channels.generic.websocket import AsyncWebsocketConsumer
from .game_room import GameRoom
from user_service.models import CustomUser
from match_making.models import MatchMakingQueue, LiveGames
from channels.db import database_sync_to_async
from urllib.parse import parse_qs
from django.conf import settings
from chat.models import Message
from django.db.models import Q
from asgiref.sync import sync_to_async
from django.db.utils import IntegrityError

load_dotenv()
active_online_games = dict()
active_local_games = dict()
active_lobbies = {}
logger = logging.getLogger('gameconsumers')
ABORTED = 1
CONCEDE = 2

## Dedicated consumer for WS Health Check
class GameHealthConsumer(AsyncWebsocketConsumer):
	async def connect(self):
		self.game_group_name = 'game_health_check'
		await self.channel_layer.group_add(
			self.game_group_name,
			self.channel_name
		)
		await self.accept()
		await self.send(text_data=json.dumps({
			'type': 'player_assignment',
			'player_id': 'p1',
			'game_id': 'health_check'
		}))

	async def disconnect(self, close_code):
		await self.channel_layer.group_discard(
			self.game_group_name,
			self.channel_name
		)

	async def receive(self, text_data):
		try:
			data = json.loads(text_data)
			if data['type'] == 'player_ready':
				print("Received player ready, sending game state")  # Debug log
				# Send game state update directly, no need for channel layer in health check
				await self.send(text_data=json.dumps({
					'type': 'game_state_update',
					'game_state': {
						'status': 'playing',
						'ball': {'x': 400, 'y': 300, 'radius': 10},
						'paddles': {
							'p1': {'x': 50, 'y': 250, 'width': 10, 'height': 100},
							'p2': {'x': 740, 'y': 250, 'width': 10, 'height': 100}
						},
						'score': {'p1': 0, 'p2': 0}
					}
				}))
		except json.JSONDecodeError as e:
			print(f"Error decoding message: {e}")

class GameConsumer(AsyncWebsocketConsumer):
	def __init__(self, *args, **kwargs):
		super().__init__(*args, **kwargs)
		self.assigned_room = -1
		self.player_id = -1
		self.connected = False
		self.already_in_game = False
		self.match_task = None
		self.receive_methods = {
				"join_private_match":self.join_lobby,
				"create_local_match":self.create_local_match,
				"create_private_match": self.create_private_lobby,
				"join_queue": self.join_queue,
				"create_ai_match": self.create_ai_lobby,
				"player_ready": self.update_ready_status,
				"player_input": self.receive_player_input,
				"rejoin_room": self.rejoin_room,
		}

	async def connect(self):
		user = await self.authenticate_user()
		if user is None:
			await self.close()
			return
		self.user = user
		logger.info(f"{self.user.id}: WebSocket connection attempt {self.scope['path']} by user {self.user.id}")
		print(user.id, user.alias, "is connected")
		self.connected = True
		try:
			await self.accept()
			await self.send(json.dumps({
				"type": "notice",
				"message": "Connection established"
			}))
			logger.info(f"{self.user.id}: accepted connection")
			if await self.check_for_existing_room():
				self.already_in_game = True
		except Exception as e:
			logger.error(f"WebSocket connection error: {e}")

	async def check_for_existing_room(self):
		for stray_room_id, room_data in active_online_games.items():
			player_ids = room_data["player_data"]["ids"]
			if self.user.id in player_ids:
				index = player_ids.index(self.user.id)
				if self.user.id is not room_data['room_data'].get_missing_player_id():
					logger.warning(f"{self.user.id}: User found to be already connected to active gameRoom")
					await self.send(json.dumps({
						"type": "already_in_game",
						"message": "User is already connected and active in a game",
						}))
					logger.info(f"{self.user.id}: sent already in game notice to client")
					return True
				else:
					logger.info(f"{self.user.id}: Match found in active online games for user")
					index = player_ids.index(self.user.id)
					room_data["player_data"]["connection"][index] = self
					self.assigned_room = stray_room_id
					player_sides = [room_data['room_data'].left_player, room_data['room_data'].right_player]
					await self.send(json.dumps({
								"type": "rejoin_room_query",
								"message": "stray game room found, rejoin?",
								"room_name": stray_room_id,
                                "players": player_sides
								}))
					logger.info(f"{self.user.id}: sent rejoin notice to client")
					return True
			return False

	async def disconnect(self, code):
		logger.info(f"{self.user.id}: Websocket connection closed")
		self.connected = False
		#deleting lobby data
		await self.delete_player_data_from_queue()
		if self.match_task and not self.match_task.done():
			self.match_task.cancel()
			try:
				await self.match_task
			except asyncio.CancelledError:
				pass
		print(f"User {self.user.id} disconnected")
		logger.info(f"User self.assigned_room: {self.assigned_room}")
		for lobby_id, lobby_data in active_lobbies.items():
			players_ids = lobby_data["players"]
			if self.user.id in players_ids:
				lobby = active_lobbies[lobby_id]
				if lobby:
					if lobby["game_type"]["is_local"] or len(lobby["players"]) == 1:
						del active_lobbies[lobby_id]
						deleted_count = await sync_to_async(Message.objects.filter(game_room=lobby_id).delete)()
						logger.info(f"Deleted {deleted_count} invitation(s) for game_lobby {self.assigned_room}")
						break
					else:
						if self.user.id in lobby["players"]:
							lobby["players"].remove(self.user.id)
						if self in lobby["connection"]:
							lobby["connection"].remove(self)
						if self.user.id in lobby["ready"]:
							lobby["ready"].remove(self.user.id)
						await lobby["connection"][0].send(json.dumps({
						"type": "set_player_1",
						}))
					print("succesfull removal")
		if hasattr(self, 'current_group'):
			await self.channel_layer.group_discard(self.current_group, self.channel_name)

	# TODO:
	# Tournaments
	# Random match
	# leave a lobby

	async def receive(self, text_data=None, bytes_data=None):
		if text_data is None:
			return
		data = json.loads(text_data)
		action = data.get("action")
		#logger.info(f"Action: {action}")
		if action in self.receive_methods.keys():
			#logger.info(f"Found receive_methods key, calling function {self.receive_methods[action]}")
			await self.receive_methods[action](data)
		else:
			await self.send(json.dumps({
				"type": "error",
				"message": f"Unrecognized action {action}"
				}))

	async def receive_player_input(self, data):
		roomID = data['game_roomID']
		local_game = data['local']
		player_id = self.user.id
		if local_game is False:
			if roomID in active_online_games:
				game_room = active_online_games[roomID]["room_data"]
                #logger.info(f"{self.user.id}: Received player input")
				await game_room.receive_player_input(player_id, data['input'])
                #logger.info(f"{self.user.id}: Forwarded player input")
			else:
				await self.send(json.dumps({
					"type": "error",
					"message": f"Game room {data['game_roomID']} not found"
					}))
		else:
			if roomID in active_local_games.keys():
				game_room = active_local_games[roomID]["room_data"]
				player_id = data['player_id']
				#logger.info(f"{self.user.id}: Received player input")
				await game_room.receive_player_input(player_id, data['input'])
				#logger.info(f"{self.user.id}: Forwarded player input")
			else:
				await self.send(json.dumps({
					"type": "error",
					"message": f"Game room {data['game_roomID']} not found"
					}))

	async def rejoin_room(self, data):
		if data["response"] is True:
			logger.info(f"{self.user.id}: rejoining gameRoom: {self.assigned_room}")
			if self.assigned_room in active_online_games.keys():
				room = active_online_games[self.assigned_room]
				await room["room_data"].player_rejoin(self.user.id, self)
			else:
				await self.send(json.dumps({
					"type": "game_aborted",
					"message": f"Game room {self.assigned_room} was aborted or cancelled and no longer exists"
					}))
				self.assigned_room = -1
		else:
			if self.assigned_room in active_online_games.keys():
				room = active_online_games[self.assigned_room]
				logger.info(f"{self.user.id}: declined rejoining gameRoom: {self.assigned_room}\ngameRoom given CONCEDE order")
				room["room_data"].set_server_order(CONCEDE)
			self.assigned_room = -1
			self.already_in_game = False

	async def create_ai_lobby(self, data):
		logger.info(f"{self.user.id}: check for ai creation")
		if not await self.check_duplicates_player():
			return
		if self.already_in_game or await self.check_for_existing_room():
			return
		room_name = str(uuid.uuid4())
		self.assigned_room = room_name
		player_id = self.user.id
		difficulty = data.get('difficulty', 'medium')
		game_type = {
			"is_online": False,
			"is_local": False,
			"is_ai": True,
			"is_quick_match": False
		}
		self.game_type = game_type
		active_lobbies[room_name] = {
			"players": [player_id],
			"ready": [],
			"connection": [self],
			"local": False,
			"is_ai_game": True,
			"difficulty": difficulty,
			"game_type": game_type
		}
		self.current_group = f"lobby_{room_name}"
		await self.channel_layer.group_add(self.current_group, self.channel_name)
		game_type = "AI Game"
		await self.send(json.dumps({
			"type": "ai_room_creation",
			"message": f"Created {game_type} Lobby {room_name}",
			"room_name": room_name,
			"is_ai_game": True,
			"difficulty": difficulty,
			"player1_alias": self.user.alias,
			"player1_id" : player_id
		}))

	async def join_queue(self, data):
		logger.info(f"{self.user.id}: check for join queue")
		if not await self.check_duplicates_player():
			return
		logger.info(f"{self.user.id}: Joining quick match")
		try:
			queue_entry = await sync_to_async(MatchMakingQueue.objects.create)(player=self.user)
			await self.send(json.dumps({
				"type":"notice",
				"message":f"User {self.user.id} added to queue"
			}))
			self.match_task = asyncio.create_task(self.get_matched(queue_entry))
			# await self.get_matched(queue_entry)
		except IntegrityError:
			await self.send(json.dumps({
				"type":"error",
				"message":"User is already in the queue"
			}))

	async def get_matched(self, queue_entry):
		logger.info(f"{self.user.id}: Starting get_matched")
		while self.connected:
			is_matched = await sync_to_async(queue_entry.match_players)()
			existing_game = await sync_to_async(
				LiveGames.objects.filter(
					Q(p1=self.user) | Q(p2=self.user),
					status=LiveGames.Status.not_started
				).exists
			)()
			matched = is_matched or existing_game
			logger.info(f"{self.user.id}: {matched} for user")
			if matched:
				game = await sync_to_async(
					LiveGames.objects.filter(
						Q(p1=self.user) | Q(p2=self.user)
					).first
				)()
				logger.info(f"{self.user.id}: Game found: {game}")
				if not game:
					continue
				logger.info(f"{self.user.id}: Game status: {game.status}")
				if game.status != LiveGames.Status.not_started:
					await self.send(json.dumps({
						"type":"error",
						"message":"this user is already in an active game"
					}))
					break

				is_p1 = await sync_to_async(lambda: game.p1 == self.user)()
				logger.info(f"{self.user.id}: Is P1: {is_p1}")
				if is_p1:
					logger.info(f"{self.user.id}: user one is creating the game ")
					await self.create_quick_match_lobby(game)
					return
				timeout = 15
				elapsed = 0
				room_name = str(game.gameUID)
				while room_name not in active_lobbies:
					if elapsed >= timeout:
						await self.send(json.dumps({
							"type": "error",
							"message": "Failed to join the lobby. Timeout exceeded."
						}))
						return
					await asyncio.sleep(1)
					elapsed += 1
				logger.info(f"{self.user.id}: user two is joining the game")
				await self.send(json.dumps({
					"type": "room_creation",
					"message": f"Created Lobby {room_name}",
					"room_name": room_name,
					"is_ai_game": False
					}))
				break
			await asyncio.sleep(5)
		logger.info(f"{self.user.id}: leaving the queue")

	async def create_quick_match_lobby(self, game):
		logger.info(f"{self.user.id}: check for create quick match")
		if not await self.check_duplicates_player():
			return
		logger.info(f"{self.user.id}: Creating quickmatch lobby")
		room_name = str(game.gameUID)
		game_type = {
			"is_online": True,
			"is_local": False,
			"is_ai": False,
			"is_quick_match": True
		}
		self.game_type = game_type
		active_lobbies[room_name] = {
				"players": [],
				"ready": [],
				"connection": [],
				"local": False,
				"is_ai_game": False,
				"difficulty": None,
				"game_type": game_type
				}
		await self.send(json.dumps({
			"type": "room_creation",
			"message": f"Created Lobby {room_name}",
			"room_name": room_name,
			"is_ai_game": False
		}))


	async def create_private_lobby(self, data):
		logger.info(f"{self.user.id}: check for create private creation")
		if not await self.check_duplicates_player():
			return
		logger.info(f"{self.user.id}: Creating private lobby")
		room_name = str(uuid.uuid4())
		game_type = {
			"is_online": True,
			"is_local": False,
			"is_ai": False,
			"is_quick_match": False
		}
		self.game_type = game_type
		active_lobbies[room_name] = {
				"players": [],
				"ready": [],
				"connection": [],
				"local": False,
				"is_ai_game": False,
				"difficulty": None,
				"game_type": game_type
				}
		await self.send(json.dumps({
			"type": "room_creation",
			"message": f"Created Lobby {room_name}",
			"room_name": room_name,
			"is_ai_game": False,
			}))

	async def create_local_match(self, data):
		logger.info(f"{self.user.id}: check for create local creation")
		if not await self.check_duplicates_player():
			return
		if self.already_in_game or await self.check_for_existing_room():
			return
		room_name = str(uuid.uuid4())
		self.assigned_room = room_name
		player_id = self.user.id
		game_type = {
			"is_online": False,
			"is_local": True,
			"is_ai": False,
			"is_quick_match": False
		}
		active_lobbies[room_name] = {
			"players": [player_id],
			"connection": [self],
			"local": True,
			"is_ai_game": False,
			"difficulty": None,
			"game_type": game_type
		}
		await self.send(json.dumps({
			"type": "local_room_creation",
			"message": f"Created local match Lobby {room_name}",
			"room_name": room_name,
			"player1_alias": self.user.alias,
			"player1_id" : player_id,
			"player2_id": -player_id
			}))

	async def join_lobby(self, data):
		logger.info(f"{self.user.id}: check for join lobby")
		if not await self.check_duplicates_player():
			return
		room_name = data["room_name"]
		player_id = self.user.id
		if room_name not in active_lobbies:
			await self.send(json.dumps({
				"type": "join_error",
				"reason": "non-existing",
				"message": f"{room_name} does not exist",
				"room_name": f"{room_name}"
				}))
			return
		self.current_group = f"lobby_{room_name}"
		if len(active_lobbies[room_name]["players"]) >= 2:
			await self.send(json.dumps({
				"type": "join_error",
				"reason": "full",
				"message": f"{room_name} is full",
				"room_name": f"{room_name}"
				}))
			return
		elif len(active_lobbies[room_name]["players"]) == 0:
			self.assigned_room = room_name
			active_lobbies[room_name]["players"].append(player_id)
			active_lobbies[room_name]["connection"].append(self)
			await self.channel_layer.group_add(self.current_group, self.channel_name)
			await self.send(json.dumps({
			"type": "set_player_1",
			}))
			return
		# if active_lobbies[room_name]["game_type"]["is_quick_match"]:
			# await self.delete_player_data_from_livegames()
		self.assigned_room = room_name
		active_lobbies[room_name]["players"].append(player_id)
		active_lobbies[room_name]["connection"].append(self)
		await self.channel_layer.group_add(self.current_group, self.channel_name)
		for connection in active_lobbies[room_name]["connection"]:
			await connection.send(json.dumps({
				"type": "join",
				"message": f"Player {player_id} joined lobby {room_name}",
				"player1": f"{active_lobbies[room_name]['players'][0]}",
				"player2": f"{active_lobbies[room_name]['players'][1]}"
				}))

	async def update_ready_status(self, data):
		room_name = data["room_name"]
		player_id = self.user.id
		if room_name not in active_lobbies:
			logger.warning(f"{self.user.id}: {room_name} does not exist when trying to update ready status")
			await self.send(json.dumps({
				"type": "join_error",
				"reason": "non-existing",
				"message": f"{room_name} does not exist",
				"room_name": f"{room_name}"
				}))
			return
		if "ready" not in active_lobbies[room_name]:
			active_lobbies[room_name]["ready"] = []
		if room_name in active_lobbies:
			if player_id not in active_lobbies[room_name].get("ready", []):
				active_lobbies[room_name]["ready"].append(player_id)
				logger.info(f"{self.user.id}: Player has readied up")
				for connection in active_lobbies[room_name]["connection"]:
					await connection.send(json.dumps({
						"type": "notice",
						"message": f"Player {player_id} is ready"
						}))
		if (
			(len(active_lobbies[room_name]["players"]) == 2)
			or
			(len(active_lobbies[room_name]["players"]) == 1 and not active_lobbies[room_name]["game_type"]["is_online"])
		) and self.all_ready(room_name):
			try:
				await self.launch_game(room_name)
			except:
				logger.error(f"{self.user.id}: Exception caught when launching game room: {room_name}")
				raise

	async def check_duplicates_player(self):
		for stray_room_id, room_data in active_lobbies.items():
			logger.warning(f"{self.user.id}: found player already in room: {room_data}")
			if self.user.id in room_data["players"]:
				await self.send(json.dumps({
				"type": "join_error",
				"reason": "duplicates",
				"message": "player is already in lobby",
				}))
				return False
		return True


	async def launch_game(self, room_name):
		try:
			for connection in active_lobbies[room_name]["connection"]:
				await connection.send(json.dumps({
					"type": "notice",
					"message": "Game is starting"
					}))
			logger.info(f"{self.user.id}: Starting game id: {room_name}, room: {active_lobbies[room_name]}")
			game_room = GameRoom(room_name,
						active_lobbies[room_name]["players"],
						active_lobbies[room_name]["connection"],
						active_lobbies[room_name]["game_type"],
						active_lobbies[room_name]["difficulty"]
						)
			logger.info(f"{self.user.id}: GameRoom created")
			logger.info(f"{self.user.id}: Checking for local")
			if active_lobbies[room_name]["local"]:
				logger.info(f"{self.user.id}: Local is true")
				active_local_games[room_name] = {
					"room_data": game_room,
					"player_data": {
					"connection": active_lobbies[room_name]["connection"],
					"ids": active_lobbies[room_name]["players"]
					}}
			else:
				active_online_games[room_name] = {
					"room_data": game_room,
					"player_data": {
					"connection": active_lobbies[room_name]["connection"],
					"ids": active_lobbies[room_name]["players"],
					}}
			game_task = asyncio.create_task(game_room.run())
			self.assigned_room = -1
			del active_lobbies[room_name]
			deleted_count = await sync_to_async(Message.objects.filter(game_room=room_name).delete)()
			logger.info(f"{self.user.id}: Deleted {deleted_count} invitation(s) for game_room {room_name}")
			game_task.add_done_callback(lambda task: self.handle_game_task_completion(task, room_name))
			logger.info(f"{self.user.id}: GameRoom task added")
		except Exception as e:
			logger.error(f"{self.user.id}: Failed to start the gameroom: {str(e)}")
			await self.send(json.dumps({
				"type": "error",
				"error": f"Failed to start game: {str(e)}"
				}))

	def handle_game_task_completion(self, task, room_name):
		try:
			logger.info(f"{self.user.id}: Game Room complete")
		except asyncio.CancelledError:
			logger.error(f"{self.user.id}: Game task was cancelled")
		except Exception as e:
			logger.error(f"{self.user.id}: Game task encountered error: {e}")
			raise
		finally:
			result = task.result()
			if result is ABORTED:
				logger.info(f"{self.user.id}: gameRoom was aborted")
			self.assigned_room = -1
			if room_name in active_local_games.keys():
				logger.info(f"{self.user.id}: Removing gameRoom {room_name} from active_local_games")
				del active_local_games[room_name]
			else:
				logger.info(f"{self.user.id}: Removing gameRoom {room_name} from active_online_games")
				del active_online_games[room_name]

	def all_ready(self, room_name):
		if room_name not in active_lobbies:
			return False
		players = active_lobbies[room_name].get("players", [])
		ready_players = active_lobbies[room_name].get("ready", [])
		return set(players) == set(ready_players)

	async def authenticate_user(self):
		query_string = self.scope["query_string"].decode("utf-8")
		query_params = parse_qs(query_string)

		token = query_params.get("token", [None])[0]
		if not token:
			return None
		try:
			payload = jwt.decode(token, settings.SECRET_KEY, algorithms=["HS256"])
			user = await self.get_user_from_payload(payload)
			return user
		except jwt.ExpiredSignatureError:
			logger.warning(f"{self.user.id}: JWT token has expired")
			return None
		except jwt.InvalidTokenError:
			logger.warning(f"{self.user.id}: Invalid JWT token")
			return None

	@database_sync_to_async
	def get_user_from_payload(self, payload):
		user_id = payload.get('user_id')
		if user_id:
			try:
				return CustomUser.objects.get(id=user_id)
			except CustomUser.DoesNotExist:
				return None
		return None

	# @database_sync_to_async
	# def delete_player_data_from_livegames(self):
	# 	LiveGames.objects.filter(Q(p1=self.user) | Q(p2=self.user)).delete()

	@database_sync_to_async
	def delete_player_data_from_queue(self):
		deleted_count, _ = MatchMakingQueue.objects.filter(player=self.user).delete()
		logger.info(f"{self.user.id}: Deleted {deleted_count} entries for user {self.user.id} in MatchMakingQueue")
