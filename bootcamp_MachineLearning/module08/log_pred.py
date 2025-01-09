# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    log_pred.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 09:54:50 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 09:59:48 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import matplotlib.pyplot as plt
from sigmoid import sigmoid_

def predict(x, theta):
    return np.dot(np.c_[np.ones(len(x)), x], theta)

def logistic_predict_(x, theta):
    return sigmoid_(predict(x, theta))




if __name__ == '__main__':

    x = np.array([4]).reshape((-1, 1))
    theta = np.array([[2], [0.5]])
    print(logistic_predict_(x, theta))
    x2 = np.array([[4], [7.16], [3.2], [9.37], [0.56]])
    theta2 = np.array([[2], [0.5]])
    print(logistic_predict_(x2, theta2))

