# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    log_loss.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:04:57 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 10:11:12 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from sigmoid import sigmoid_
from log_pred import logistic_predict_

def log_loss_(y, y_hat, eps=1e-15):
    loss = 0
    for i in range(len(y)):
        loss += y[i] * np.log(y_hat[i]) + (1 - y[i]) * np.log(1 - y_hat[i])
    return (-loss/len(y))

if __name__ == '__main__':
    y1 = np.array([1]).reshape((-1, 1))
    x1 = np.array([4]).reshape((-1, 1))
    theta1 = np.array([[2], [0.5]])
    y_hat1 = logistic_predict_(x1, theta1)
    print(log_loss_(y1, y_hat1))
    y2 = np.array([[1], [0], [1], [0], [1]])
    x2 = np.array([[4], [7.16], [3.2], [9.37], [0.56]])
    theta2 = np.array([[2], [0.5]])
    y_hat2 = logistic_predict_(x2, theta2)
    print(log_loss_(y2, y_hat2))


