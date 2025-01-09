# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_linear_regression.py                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 10:08:30 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 13:30:24 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import csv
import matplotlib.pyplot as plt

class MyLinearRegression():
    
    def __init__(self, thetas, alpha=0.001, max_iter=1000):
        self.alpha = alpha
        self.max_iter = max_iter
        self.thetas = thetas
    
    def gradient_(self, x, y):
        x = np.c_[np.ones(len(x)), x]
        return (np.dot(x.T, (np.dot(x, self.thetas) - y)))/len(x)

    def fit_(self, x, y, thetas):
        for i in range(self.max_iter):
            thetas = thetas - self.alpha * self.gradient_(x, y)
        return thetas

    def predict_(self, x, thetas):
        x_inter = np.c_[np.ones(len(x)), x]
        y_hat = np.dot(x_inter, thetas)
        self.y_hat = y_hat
        return y_hat

    def loss_elem_(self, y, y_hat):
        result = np.zeros((len(y), 1))
        for i in range(len(y)):
            result[i][0] = np.square(y[i][0] - y_hat[i][0])
        return result

    def loss_(self, y, y_hat):
        result = np.mean(self.loss_elem_(y, y_hat))
        return result/2
    
    def mse_(y, y_hat):
        result = np.zeros((len(y), 1))
        for i in range(len(y)):
            result[i][0] = np.square(y[i][0] - y_hat[i][0])
        result_f = np.mean(result)
        return result_f

    def plot_with_loss(self, x, y, theta):
        plt.scatter(x, y)
        y_curv = predict_(x, theta)
        plt.plot(x, y_curv, color = 'red')
        plt.title(f"cost = {vect_loss_(y, y_curv)}")
        for i in range(len(y)):
            plt.plot([x[i],x[i]], [y[i], y_curv[i]], '--', color = "y")
        plt.show()

def plot_graphs(x, y, thetas):
    MLR = MyLinearRegression(thetas)
    figure, axis = plt.subplots(2, 1)
    axis[0].scatter(x, y, label = 'Strue(pills)', color ='b')
    y_hat = MLR.predict_(x, thetas)
    axis[0].scatter(x, y_hat, label = 'Spredict(pills)', color = 'g')
    axis[0].plot(x, y_hat,':', color = 'g')
    axis[0].set_xlabel('Quantity of blue pills (in micrograms)')
    axis[0].set_ylabel('Space driving score')
    axis[0].legend()
    axis[1].set_xlabel('theta1')
    axis[1].set_ylabel('cost function J(theta0, theta1)')
    for i in range (5):
        thetas1 = np.linspace(-15, 0, 30)
        loss_thetas1 = []
        print(MLR.loss_(y, MLR.predict_(x, thetas)))
        for j in thetas1:
            a,b = float(j), float(thetas[0][0])
            y_hat = MLR.predict_(x, np.array([[b],[a]]))
            loss_thetas1.append(MLR.loss_(y, y_hat))
        axis[1].plot(thetas1, np.array(loss_thetas1), label = f'J(theta0 = c{i}*theta1')
        axis[1].scatter(thetas[1], MLR.loss_(y, MLR.predict_(x, thetas)))
        thetas = MLR.fit_(x, y, thetas)
    axis[1].legend()
    axis[1].set_xlim(-100, 100)
    axis[1].set_ylim(-0, 300)
    plt.show()

if __name__ == '__main__':
    path = 'are_blue_pills_magics.csv'
    with open(path, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
    data_array = np.array(data[1:], dtype = float)
    #data = data_array[1:,1:]
    x = data_array[:,1].reshape(-1, 1)
    y = data_array[:,2].reshape(-1, 1)
    theta1 = np.array([[89.0], [-8]])
    plot_graphs(x, y, theta1)
    
