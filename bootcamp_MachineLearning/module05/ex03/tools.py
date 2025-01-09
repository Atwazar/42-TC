# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tools.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:26:49 by thelaine          #+#    #+#              #
#    Updated: 2024/06/17 11:35:23 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def add_intercept(x):
    if not isinstance(x, np.ndarray) or len(x) == 0:
        return None
    return np.c_[x, np.ones(len(x))]

if __name__=='__main__':
    x = np.arange(1, 6)
    print(type(x))
    print(x)
    inter = add_intercept(x)
    print(inter)
