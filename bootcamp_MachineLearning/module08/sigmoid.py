# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sigmoid.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 09:45:37 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 09:57:43 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import matplotlib.pyplot as plt

def sigmoid_(x):
    sigmoid = np.zeros(x.shape)
    for i in range(len(x)):
        sigmoid[i]+= 1 / (1 + np.exp(-x[i]))
    return sigmoid

if __name__ == '__main__':
    x = np.array([[-4], [2], [0]])
    print(sigmoid_(x))
    xprime = np.linspace(-10,10, 100)
    y = sigmoid_(xprime)
    plt.plot(xprime, y)
    plt.show()


        
