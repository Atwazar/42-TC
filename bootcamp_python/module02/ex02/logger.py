# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    logger.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 11:09:03 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 12:27:43 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
from random import randint
import os
import string


def log(funct):
    def inter(*args):
        start_time = time.time()
        funct(*args)
        end_time = time.time()
        exec_time = end_time - start_time
        exec_time = exec_time * 1000
    
        with open("machine.log", 'a') as t:
            t.write(f"Running: {funct.__name__}\t [exec-time = {exec_time} s]\n")
    return inter
class CoffeeMachine():
    water_level = 100
    @log

    def start_machine(self):
        if self.water_level > 20:
            return True
        else:
            print("Please add water!")
            return False
    
    @log
    def boil_water(self):
        return "boiling..."
    
    @log
    def make_coffee(self):
        if self.start_machine():
            for _ in range(20):
                time.sleep(0.01)
                self.water_level -= 1
            print(self.boil_water())
            print("Coffee is ready!")
    
    @log
    def add_water(self, water_level):
        time.sleep(randint(1, 5))
        self.water_level += water_level
        print("Blub blub blub...")

if __name__ == "__main__":
        machine = CoffeeMachine()
        for i in range(0, 5):
            machine.make_coffee()

machine.make_coffee()
machine.add_water(70)
