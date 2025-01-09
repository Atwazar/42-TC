# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    log_gradient.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:23:18 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 10:47:29 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from sigmoid import sigmoid_
from log_pred import logistic_predict_
from log_loss import log_loss_
from vec_log_loss import vec_log_loss_

def log_gradient(x, y, theta):
    gradient = np.zeros((len(theta), 1)).reshape(-1, 1)
    print(gradient)
    y_hat = logistic_predict_(x, theta)
    print(y_hat.shape, y.shape, x.shape, gradient.shape)
    for i in range(len(theta)):
        for j in range(len(x[0])):
            print(j)
            gradient[i][0] += (y_hat[i][0] - y[i][0]) * x[i][0]
    return gradient / len(x)

if __name__ == '__main__':
    y1 = np.array([1]).reshape((-1, 1))
    x1 = np.array([4]).reshape((-1, 1))
    theta1 = np.array([[2], [0.5]])
    print(log_gradient(x1, y1, theta1))

    y2 = np.array([[1], [0], [1], [0], [1]])
    x2 = np.array([[4], [7.16], [3.2], [9.37], [0.56]])
    theta2 = np.array([[2], [0.5]])
    print(log_gradient(x2, y2, theta2))

