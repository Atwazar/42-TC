# python manage.py test game_service.consumerTest
import json
import logging
import asyncio
from channels.testing import WebsocketCommunicator
from channels.routing import URLRouter
from django.test import TestCase
from .routing import websocket_urlpatterns  # Import your WebSocket URL routes
from .consumers import GameConsumer  # Import your consumer

logger = logging.getLogger(__name__)
class GameConsumerTest(TestCase):
    async def test_connection(self):
        # Create a communicator with the consumer
        communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
        connected, _ = await communicator.connect()

        # Assert the connection was successful
        self.assertTrue(connected)

        # Check the initial connection message
        response = await communicator.receive_json_from()
        self.assertEqual(response['type'], 'notice')
        self.assertEqual(response['message'], 'Connection established')

        await communicator.disconnect()

    async def test_create_private_match(self):
        communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
        await communicator.connect()

        response = await communicator.receive_json_from()
        self.assertEqual(response['type'], 'notice')
        self.assertEqual(response['message'], 'Connection established')

        # Send create private match request
        await communicator.send_json_to({
            "action": "create_private_match",
            "id": "player1"
        })

        # Check the response response = await communicator.receive_json_from()
        response = await communicator.receive_json_from()
        print(json.dumps(response, indent=4))
        self.assertEqual(response['type'], 'room_creation')
        self.assertIn('room_name', response)

        await communicator.disconnect()

    async def test_join_private_match(self):
        # First, create a room
        creator_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
        await creator_communicator.connect()
        response = await creator_communicator.receive_json_from()
        self.assertEqual(response['type'], 'notice')
        self.assertEqual(response['message'], 'Connection established')

        await creator_communicator.send_json_to({
            "action": "create_private_match",
            "id": "player1"
        })
        room_response = await creator_communicator.receive_json_from()
        room_name = room_response['room_name']

        # Now try to join the room
        joiner_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
        await joiner_communicator.connect()

        response = await joiner_communicator.receive_json_from()
        self.assertEqual(response['type'], 'notice')
        self.assertEqual(response['message'], 'Connection established')

        await joiner_communicator.send_json_to({
            "action": "join_private_match",
            "room_name": room_name,
            "id": "player2"
        })

        join_response = await joiner_communicator.receive_json_from()
        print(json.dumps(join_response, indent=4))
        self.assertEqual(join_response['type'], 'notice')
        self.assertEqual(join_response['message'], f'Player player2 joined lobby {room_name}')

        await creator_communicator.disconnect()
        await joiner_communicator.disconnect()

    async def test_local_room_creation(self):
        creator_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
        await creator_communicator.connect()
        creation_response = await creator_communicator.receive_json_from()
        self.assertEqual(creation_response['type'], 'notice')
        self.assertEqual(creation_response['message'], 'Connection established')

        await creator_communicator.send_json_to({
            "action": "create_local_match",
            "id": "player1"
            })
        creation_response = await creator_communicator.receive_json_from()
        self.assertEqual(creation_response['type'], 'local_room_creation')
        print(json.dumps(creation_response, indent=4))

        await creator_communicator.disconnect()

    async def test_local_match(self):
       creator_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
       await creator_communicator.connect()
       await creator_communicator.receive_json_from()
       await creator_communicator.send_json_to({
           "action": "create_local_match",
           "id": "player1"
           })
       creation_response = await creator_communicator.receive_json_from()
       print(json.dumps(creation_response, indent=4))
       player_2 = creation_response['player2_id']
       room_name = creation_response['room_name']
       await creator_communicator.send_json_to({
           "action": "player_ready",
           "player_id": "player1",
           "room_name": room_name
           })
       await creator_communicator.receive_json_from()
       await creator_communicator.receive_json_from()
       await creator_communicator.receive_json_from()
       update_messages = []
       while True:
             await creator_communicator.send_json_to({
                 'type': 'player_input',
                 'game_roomID': room_name,
                 'player_id': 'player1',
                 'input': 'move_up',
                 })
             await creator_communicator.send_json_to({
                 'type': 'player_input',
                 'game_roomID': room_name,
                 'player_id': player_2,
                 'input': 'move_down',
                 })
             update_message = await asyncio.wait_for(creator_communicator.receive_json_from(),
                                                     timeout=1)
             print(json.dumps(update_message, indent=4))
             if update_message['type'] == 'game_over':
                 break
             update_messages.append(update_message)
             self.assertEqual(update_message['type'], 'game_update')
             self.assertIn('payload', update_message)
             payload = update_message['payload']
             self.assertIn('players', payload)
             self.assertIn('ball', payload)

             for player_id, player_data in payload['players'].items():
                 self.assertIn('x', player_data)
                 self.assertIn('y', player_data)
                 self.assertIn('score', player_data)
             self.assertIn('x', payload['ball'])
             self.assertIn('y', payload['ball'])
             self.assertIn('radius', payload['ball'])
       await creator_communicator.disconnect()       

#     async def test_player_ready(self):
#         # Create a room and have two players join
#         creator_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
#         await creator_communicator.connect()

#         creation_response = await creator_communicator.receive_json_from()
#         self.assertEqual(creation_response['type'], 'notice')
#         self.assertEqual(creation_response['message'], 'Connection established')
#         print(json.dumps(creation_response, indent=4))
#         await creator_communicator.send_json_to({
#             "action": "create_private_match",
#             "id": "player1"
#         })
#         room_response = await creator_communicator.receive_json_from()

#         print(json.dumps(room_response, indent=4))
#         room_name = room_response['room_name']

#         joiner_communicator = WebsocketCommunicator(URLRouter(websocket_urlpatterns), "/ws/game-server/test_room/")
#         await joiner_communicator.connect()

#         await joiner_communicator.receive_json_from()

#         await joiner_communicator.send_json_to({
#             "action": "join_private_match",
#             "room_name": room_name,
#             "id": "player2"
#         })
#         await creator_communicator.receive_json_from()
#         await joiner_communicator.receive_json_from()

#         # Ready up both players
#         print("===Testing consumer player readying notice====")
#         await creator_communicator.send_json_to({
#             "action": "player_ready",
#             "room_name": room_name,
#             "player_id": "player1"
#         })
#         creator_response = await creator_communicator.receive_json_from()
#         self.assertEqual(creator_response['type'], 'notice')
#         print(json.dumps(creator_response, indent=4))
#         joiner_response = await joiner_communicator.receive_json_from()
#         self.assertEqual(joiner_response['type'], 'notice')
#         print(json.dumps(joiner_response, indent=4))

#         await joiner_communicator.send_json_to({
#             "action": "player_ready",
#             "room_name": room_name,
#             "player_id": "player2"
#         })
#         creator_response = await creator_communicator.receive_json_from()
#         self.assertEqual(creator_response['type'], 'notice')
#         print(json.dumps(creator_response, indent=4))
#         joiner_response = await joiner_communicator.receive_json_from()
#         self.assertEqual(joiner_response['type'], 'notice')
#         print(json.dumps(joiner_response, indent=4))

#   #      try:
#         print("===Testing consumer game starting notice====")
#         # Check for game start notice
#         start_response = await creator_communicator.receive_json_from()
#         self.assertEqual(start_response['type'], 'notice')
#         self.assertEqual(start_response['message'], 'Game is starting')
#         print(json.dumps(start_response, indent=4))

#         start_response = await joiner_communicator.receive_json_from()
#         self.assertEqual(start_response['type'], 'notice')
#         self.assertEqual(start_response['message'], 'Game is starting')
#         print(json.dumps(start_response, indent=4))


#         print("===Testing gameRoom socket communications====")
#         # Check for game start notice
#         start_response = await creator_communicator.receive_json_from()
#         self.assertEqual(start_response['type'], 'game_start')
#         self.assertEqual(start_response['message'], 'Game has started')
#         print(json.dumps(start_response, indent=4))

#         start_response = await joiner_communicator.receive_json_from()
#         self.assertEqual(start_response['type'], 'game_start')
#         self.assertEqual(start_response['message'], 'Game has started')
#         logger.info("Game started notices reiceived by test consumers")
#         print(json.dumps(start_response, indent=4))


#         update_messages = []
#         while True:
#             logger.info("====GAME LOOP ITERATION====")
# #            print(f"room_name: {room_name}")
#             await joiner_communicator.send_json_to({
#                 'type': 'player_input',
#                 'game_roomID': room_name,
#                 'player_id': 'player2',
#                 'input': 'move_down',
#                 })
#             await creator_communicator.send_json_to({
#                 'type': 'player_input',
#                 'game_roomID': room_name,
#                 'player_id': 'player1',
#                 'input': 'move_up',
#                 })
#             update_message = await asyncio.wait_for(creator_communicator.receive_json_from(),
#                                                     timeout=1)
#             print(json.dumps(update_message, indent=4))
#             if update_message['type'] == 'game_over':
#                 break
#             update_messages.append(update_message)
#             self.assertEqual(update_message['type'], 'game_update')
#             self.assertIn('payload', update_message)
#             payload = update_message['payload']
#             self.assertIn('players', payload)
#             self.assertIn('ball', payload)

#             for player_id, player_data in payload['players'].items():
#                 self.assertIn('x', player_data)
#                 self.assertIn('y', player_data)
#                 self.assertIn('score', player_data)
#             self.assertIn('x', payload['ball'])
#             self.assertIn('y', payload['ball'])
#             self.assertIn('radius', payload['ball'])
#   #      except Exception as e:
#   #          logger.error(f"GameRoom consumer test failed: {e}")
#         await creator_communicator.disconnect()
#         await joiner_communicator.disconnect()

    # Add more test methods to cover edge cases like:
    # - Trying to join a full room
    # - Trying to create a room with an existing player
    # - Testing error handling
