# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gradient.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 09:25:44 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 10:06:20 by thelaine         ###   ########.fr        #
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
     return y_hat

def vect_loss_(y, y_hat):
    return np.dot((y_hat - y).T,(y_hat - y))/len(y)

def plot_with_loss(x, y, theta):
    plt.scatter(x, y)
    y_curv = predict_(x, theta)
    plt.plot(x, y_curv, color = 'red')
    plt.title(f"cost = {vect_loss_(y, y_curv)}")
    for i in range(len(y)):
        plt.plot([x[i],x[i]], [y[i], y_curv[i]], '--', color = "y")
    plt.show()

def simple_gradient(x, y, theta):
    y_hat = predict_(x, theta)
    J_0 = 0
    J_1 = 0
    for i in range(len(x)):
        J_0 += y_hat[i] - y[i]
        J_1 += (y_hat[i] - y[i]) * x[i]
    J_0 /= len(x)
    J_1 /= len(x)
    return (J_0, J_1)

def gradient(x, y, theta):
    x = np.c_[np.ones(len(x)), x]
    return (np.dot(x.T, (np.dot(x, theta) - y)))/len(x)

def fit_(x, y, theta, alhpa, max_iter):
    for i in range(max_iter):
        theta = theta - alpha * gradient(x, y, theta)
        if i%10000 == 0:
            print(i)
    return theta

if __name__ == '__main__':
    x = np.array([12.4956442, 21.5007972, 31.5527382, 48.9145838, 57.5088733]).reshape((-1, 1))
    y = np.array([37.4013816, 36.1473236, 45.7655287, 46.6793434, 59.5585554]).reshape((-1, 1))
    theta1 = np.array([1, 1]).reshape((-1, 1))
    alpha = 5e-8
    max_iter = 1500000
    print(simple_gradient(x, y, theta1))
    print(gradient(x, y, theta1))
    plot_with_loss(x, y, theta1)
    theta1 = fit_(x, y, theta1, alpha, max_iter)
    plot_with_loss(x, y, theta1)
    print(theta1)
    
