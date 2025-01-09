# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vec_log_loss.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:13:02 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 10:20:50 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from sigmoid import sigmoid_
from log_pred import logistic_predict_
from log_loss import log_loss_

def vec_log_loss_(y, y_hat, eps=1e-15):
    ones = np.ones(y.shape)
    return -(np.dot(y.T, np.log(y_hat)) + np.dot((ones - y).T, np.log(ones - y_hat)))/len(y)

if __name__ == '__main__':

    y1 = np.array([1]).reshape((-1, 1))
    x1 = np.array([4]).reshape((-1, 1))
    theta1 = np.array([[2], [0.5]])
    y_hat1 = logistic_predict_(x1, theta1)
    print(vec_log_loss_(y1, y_hat1))
    y2 = np.array([[1], [0], [1], [0], [1]])
    x2 = np.array([[4], [7.16], [3.2], [9.37], [0.56]])
    theta2 = np.array([[2], [0.5]])
    y_hat2 = logistic_predict_(x2, theta2)
    print(vec_log_loss_(y2, y_hat2))
