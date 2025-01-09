# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:17:56 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 12:33:34 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


class GotCharacter:
    def __init__(self, first_name, is_alive=True):
        self.first_name = first_name
        self.is_alive = is_alive
class Stark(GotCharacter):
    def __init__(self, first_name=None, is_alive=True):
        super().__init__(first_name=first_name, is_alive=is_alive)
        self.family_name = "Stark"
        self.house_words = "Winter is Coming"
    def print_house_words(self):
        print(self.house_words)
    def die(self):
        self.is_alive = False


