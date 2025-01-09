# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_logistic_regression.py                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 10:57:07 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 15:06:29 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from alive_progress import alive_bar
#import matplotlib.pyplot as plt

class MyLogisticRegression():
    def __init__(self, theta, alpha = 0.001, max_iter = 1000):
        self.alpha = alpha
        self.max_iter = max_iter
        self.theta = theta

    def sigmoid_(self, x):
        #sigmoid = np.zeros(x.shape)
        #for i in range(len(x)):
        #sigmoid[i]+= 1 / (1 + np.exp(-x[i]))
        #return sigmoid
        return 1/ (1 + np.exp(-x))

    def predict_(self, x):
        return np.dot(np.c_[np.ones(len(x)), x], self.theta)

    def logistic_predict_(self, x):
        return self.sigmoid_(self.predict_(x))

    def gradient(self, x, y):
        ones = np.ones((len(x), 1)).reshape(-1, 1)
        xprime = np.c_[ones, x]
        return np.dot(xprime.T, (self.logistic_predict_(x) - y))/len(x)

    def loss_(self, y, y_hat, eps = 1e-15):
        ones = np.ones(y.shape)
        epses = eps * ones
        return -(np.dot(y.T, np.log(y_hat + epses)) + np.dot((ones - y).T, np.log(ones - y_hat + epses)))/len(y)
    
    def mse_(self, y, y_hat):
        return np.square(np.subtract(y, y_hat)).mean()

    def fit_(self, x, y):
        with alive_bar(self.max_iter) as bar:
            for i in range(self.max_iter):
                self.theta = self.theta - self.alpha * self.gradient(x, y)
                bar()
        return self.theta
    
    def plot_scattered(self, axis, x1_title, i, data, target, predict):
        axis[i].scatter(data, target, label = 'target')
        axis[i].scatter(data, predict, label ='Predicted target')
        axis[i].set_xlabel(x1_title)
        axis[i].set_ylabel('y: target')
        axis[i].set_title(f"mse = {self.mse_(target, predict)}")
        axis[i].legend()

if __name__ == '__main__':
    X = np.array([[1., 1., 2., 3.], [5., 8., 13., 21.], [3., 5., 9., 14.]])
    Y = np.array([[1], [0], [1]])
    thetas = np.array([[2], [0.5], [7.1], [-4.3], [2.09]])
    mylr = MyLogisticRegression(thetas)
    Y_HAT = (mylr.logistic_predict_(X))
    print(Y_HAT)
    print(mylr.loss_(Y,Y_HAT))
    print(mylr.fit_(X, Y))


