# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prediction.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 11:38:02 by thelaine          #+#    #+#              #
#    Updated: 2024/06/17 12:50:16 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import matplotlib.pyplot as plt

def add_intercept(x):
    if not isinstance(x, np.ndarray) or len(x) == 0:
        return None
    return np.c_[np.ones(len(x)), x]

def predict_(x, theta):
     x_inter = add_intercept(x)
     y_hat = np.dot(x_inter, theta)
     print(y_hat)
     return y_hat

def plot(x, y ,theta):
    plt.scatter(x, y)
    y_curv = predict_(x, theta)
    plt.plot(x, y_curv, color = 'red')
    plt.show()

def loss_elem_(y, y_hat):
    result = np.zeros((len(y), 1))
    for i in range(len(y)):
        result[i][0] = np.square(y[i][0] - y_hat[i][0])
    print(result)
    return result

def loss_(y, y_hat):
    result = np.mean(loss_elem_(y, y_hat))
    return result/2

def vect_loss_(y, y_hat):
    return np.dot((y_hat - y),(y_hat - y))/len(y)

def plot_with_loss(x, y, theta):
    plt.scatter(x, y)
    y_curv = predict_(x, theta)
    plt.plot(x, y_curv, color = 'red')
    plt.title(f"cost = {vect_loss_(y, y_curv)}")
    for i in range(len(y)):
        plt.plot([x[i],x[i]], [y[i], y_curv[i]], '--', color = "y")
    plt.show()


if __name__=='__main__':
    #x = np.arange(1, 6)
    #theta1 = np.array([[5], [0]])
    #print(predict_(x, theta1))
    #theta1 = np.array([5, 0])
    #predict_(x, theta1)
    #theta2 = np.array([0, 1])
    #predict_(x, theta2)
    #theta3 = np.array([5, 3])
    #predict_(x, theta3)
    #theta4 = np.array([-3, 1])
    #predict_(x, theta4)
    #y = np.array([3.74013816, 3.61473236, 4.57655287, 4.66793434, 5.95585554])
    #theta1 = np.array([[4.5],[-0.2]])
    #plot(x, y, theta1)
    #x1 = np.array([[0.], [1.], [2.], [3.], [4.]])
    #theta1 = np.array([[2.], [4.]])
    #y_hat1 = predict_(x1, theta1)
    #y1 = np.array([[2.], [7.], [12.], [17.], [22.]])
    #print(loss_(y1, y_hat1))
    #X = np.array([0, 15, -9, 7, 12, 3, -21])
    #Y = np.array([2, 14, -13, 5, 12, 4, -19])
    #print(vect_loss_(X, Y))
    #print(vect_loss_(X, X))
    x = np.arange(1,6)
    y = np.array([11.52434424, 10.62589482, 13.14755699, 18.60682298, 14.14329568])
    theta1= np.array([18,-1])
    plot_with_loss(x, y, theta1)
    theta2 = np.array([14, 0])
    plot_with_loss(x, y, theta2)
