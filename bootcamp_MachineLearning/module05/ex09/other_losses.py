# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    other_losses.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:47:20 by thelaine          #+#    #+#              #
#    Updated: 2024/06/17 13:11:52 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def mse_(y, y_hat):
    result = np.zeros((len(y), 1))
    for i in range(len(y)):
        result[i][0] = np.square(y[i][0] - y_hat[i][0])
    result_f = np.mean(result)
    return result_f

def rmse_(y, y_hat):
    return np.sqrt(mse_(y, y_hat))

def mae_(y, y_hat):
    result = np.zeros((len(y), 1))
    for i in range(len(y)):
        result[i][0] = np.absolute(y[i][0] - y_hat[i][0])
    result_f = np.mean(result)
    return result_f
def r2score_(y, y_hat):
   return (1 - mse_(y, y_hat)/np.var(y))

x = np.array([[0], [15], [-9], [7], [12], [3], [-21]])
y = np.array([[2], [14], [-13], [5], [12], [4], [-19]])
print(mse_(x,y))
print(rmse_(x,y))
print(mae_(x,y))
print(r2score_(x,y))
