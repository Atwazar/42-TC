# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    NumPyCreator.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 09:21:52 by thelaine          #+#    #+#              #
#    Updated: 2024/06/13 09:51:48 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class NumPyCreator:
    def from_list(self, lst):
        return np.array(lst)
    def from_tuple(self, tpl):
        return np.array(tpl)
    def from_iterable(self, iterable):
        return list(np.array(iterable))
    def from_shape(self, shape, value):
        return np.full(shape, value)
    def random(self, shape):
        return np.random.randint(0, 10, shape)
    def identity(self, n):
        return np.identity(n)

if __name__ == '__main__':
    t  = NumPyCreator()
    lst = [1, 2, 3, 4]
    tpl = (1, 2, 3, 4)
    shape = (4, 4)
    value = 2
    n = 3
    print(t.from_list(lst))
    print(t.from_tuple(tpl))
    print(t.from_shape(shape, value))
    print(t.random(shape))
    print(t.identity(n))
