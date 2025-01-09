# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    data_splitter.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 12:33:07 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 12:57:44 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def data_splitter(x, y, p):
    xprime = np.c_[x, y]
    print(xprime)
    np.random.shuffle(xprime)
    i = int(len(x) * p)
    l = len(xprime[0])
    print(i)
    x1 = xprime[:i,:l - 1]
    print(x1)
    x2 = xprime[i:,:l - 1]
    print(x2)
    y1 = xprime[:i,l - 1]
    print(y1)
    y2 = xprime[i:,l - 1]
    print(y2)


if __name__ == '__main__':
    x = np.array([[ 1, 42],[300, 10],[ 59, 1],[300, 59],[10, 42]])
    y = np.array([0, 1, 0, 1, 0]).reshape((-1, 1))
    p = 0.8
    data_splitter(x, y, p)
