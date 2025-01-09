# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    polynomial_model.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 10:58:53 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 11:26:56 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def add_polynomial_features(x, power):
    x_powered = x
    for i in range(1, power):
        powered = np.ones(x.shape)
        for j in range(i + 1):
            powered *= x
        x_powered = np.c_[x_powered, powered]
    return x_powered

if __name__ == '__main__':
    x = np.arange(1,6).reshape(-1, 1)
    print(f"x= {add_polynomial_features(x, 3)}")
    print(f"x= {add_polynomial_features(x, 6)}")
