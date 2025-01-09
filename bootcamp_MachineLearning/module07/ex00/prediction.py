# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prediction.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:44:33 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 17:48:35 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def simple_predict(x, theta):
    result = np.zeros(theta.shape)
    for i in range(len(x)):
        result[i][0] = theta[0][0]
        for j in range(len(x[0])):
            result[i][0] += x[i][j] * theta[j + 1][0]
    return result

def predict(x, theta):
    return np.dot(np.c_[np.ones(len(x)), x], theta)

def gradient(x, y, theta):
    xprime = np.c_[np.ones(len(x)),x]
    return (np.dot(xprime.T,(np.dot(xprime,theta) - y)))/len(x)

def fit_(x, y, theta, alpha, max_iter):
    for i in range(max_iter):
        theta = theta - alpha * gradient(x, y, theta)
    return theta

def loss_(y, y_hat):
    return np.dot((y_hat - y).T,(y_hat - y))/(2 * len(y))

if __name__ == '__main__':
    #x = np.arange(1,13).reshape((4,-1))
    #theta1 = np.array([5, 0, 0, 0]).reshape((-1, 1))
    #theta3 = np.array([-1.5, 0.6, 2.3, 1.98]).reshape((-1, 1))
    #print(x)
    #print(simple_predict(x, theta1))
    #print(predict(x, theta1))
    #print(simple_predict(x, theta3))
    #print(predict(x, theta3))
    #x = np.array([[ -6, -7, -9],[ 13, -2, 14],[ -7, 14, -1],[ -8, -4, 6],[ -5, -9, 6],[ 1, -5, 11],[ 9, -11, 8]])
    #y = np.array([2, 14, -13, 5, 12, 4, -19]).reshape((-1, 1))
    #theta1 = np.array([0, 3, 0.5, -6]).reshape((-1, 1))
    #print(gradient(x, y, theta1))
    #x = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
    #y = np.array([[19.6], [-2.8], [-25.2], [-47.6]])
    #theta = np.array([[42.], [1.], [1.], [1.]])
    #y_hat1 = predict(x, theta)
    #loss1 = loss_(y, y_hat1) 
    #theta2 = fit_(x, y, theta, alpha = 0.0005, max_iter=42000)
    #y_hat2 = predict(x, theta2)
    #loss2 = loss_(y, y_hat2)
    #print(f"theta= {theta}\n y_hat= {y_hat1}\n loss={loss1}") 
    #print(f"theta= {theta2}\n y_hat= {y_hat2}\n loss={loss2}") 
    X = np.array([0, 15, -9, 7, 12, 3, -21]).reshape((-1, 1))
    Y = np.array([2, 14, -13, 5, 12, 4, -19]).reshape((-1, 1))
    print(loss_(X, Y)) 
