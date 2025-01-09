# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vec_log_gradient.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:50:08 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 10:56:08 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from sigmoid import sigmoid_
from log_pred import logistic_predict_
from log_loss import log_loss_
from vec_log_loss import vec_log_loss_

def vec_log_gradient(x, y, theta):
    ones = np.ones((1, len(x))).reshape(1, -1)
    xprime = np.c_[ones, x]
    return np.dot(xprime.T, (logistic_predict_(x, theta) - y))/len(x)

y1 = np.array([1]).reshape((-1, 1))
x1 = np.array([4]).reshape((-1, 1))
theta1 = np.array([[2], [0.5]])
print(vec_log_gradient(x1, y1, theta1))
