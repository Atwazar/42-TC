# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prediction.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:11:29 by thelaine          #+#    #+#              #
#    Updated: 2024/06/17 11:23:53 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def simple_predict(x, theta):
    y_hat = np.zeros((1, len(x)))
    for i in range(len(x)):
        y_hat[0][i] = theta[0] + theta[1] * x[i]
    print(y_hat)

if __name__=='__main__':
    x = np.arange(1, 6)
    theta1 = np.array([5, 0])
    simple_predict(x, theta1)
    theta2 = np.array([0, 1])
    simple_predict(x, theta2)
    theta3 = np.array([5, 3])
    simple_predict(x, theta3)
    theta4 = np.array([-3, 1])
    simple_predict(x, theta4)
