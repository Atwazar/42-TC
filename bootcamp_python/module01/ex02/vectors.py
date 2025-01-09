# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vectors.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 12:42:45 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 13:17:25 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Vector:
    def __init__(self, values):
        for vect in values:
            for scalar in vect:
                if not isinstance(scalar, float):
                    print("bad bad vector")
                    exit()
        if len(values) = 1:
            self.shape = (1, len(values[1]))
        else:
            for vect in values:
                if len(vect) != 1:
                    print("bad bad vector")
                    exit()
           self.shape = (len(values[1]), 1)
        self.values = values
    
    def __add__(self, other):
        if self.shape != other.shape:
            print("impossible addition")
        else:

            for i in range self.shape[0]:
                for j in range self.shape[1]:
                    self.value[i][j] += other.value[i][j]
            return(self)

    def __sub__(self, other):
        if self.shape != other.shape:
            print("impossible substraction")
        else:

            for i in range self.shape[0]:
                for j in range self.shape[1]:
                    self.value[i][j] -= other.value[i][j]
            return(self)

    def __mul__(self, val):
        if not isinstance(val, float):
            print("bad bad value")
            exit()
        for vect in self.values:
            for scal in vect:
                scal *= val
        return (self)
    def __div__(selv, val):
        if not isinstance(val, float) or val == 0:
            print("bad bad value")
            exit()
        for vect in self.shape:
            for scal in vect:
                scal /= val
        return (self)
    
    def dot(self, other):
        if self.shape != other.shape:
            print("impossible substraction")
        else:
            result = 0
            for i in range self.shape[0]:
                for j in range self.shape[1]:
                    result += self.value[i][j] * other.value[i][j]
            return(result)
    def T(self):
        for vect in self.list:
            for scal in vect:
                scal = 0
        return (self):


