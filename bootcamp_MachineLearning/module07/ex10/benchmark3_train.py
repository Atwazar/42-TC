# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark3_train.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:44:33 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 18:26:12 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import csv
import matplotlib.pyplot as plt
from alive_progress import alive_bar
import time

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
    with alive_bar(max_iter) as bar:
        for i in range(max_iter):
            theta = theta - alpha * gradient(x, y, theta)
            bar()
    return theta

def loss_(y, y_hat):
    return np.dot((y_hat - y).T,(y_hat - y))/(2 * len(y))

def mse_(y, y_hat):
    return np.square(np.subtract(y, y_hat)).mean()

def add_polynomial_features(x, power):
    x_powered = x
    for i in range(1, power):
        powered = np.ones(x.shape)
        for j in range(i + 1):
            powered *= x
        x_powered = np.c_[x_powered, powered]
    return x_powered


def data_splitter(x, y, p):
    xprime = np.c_[x, y]
    np.random.shuffle(xprime)
    i = int(len(x) * p)
    l = len(xprime[0])
    x1 = xprime[:i,:l - 1]
    x2 = xprime[i:,:l - 1]
    y1 = xprime[:i,l - 1]
    y2 = xprime[i:,l - 1]
    return x1, x2, y1, y2

def plot_graphs(data_array, theta, alpha, max_iter):
    
    Age = data_array[:,0].reshape(-1, 1)
    Thrust_power = data_array[:,1].reshape(-1, 1)
    Terameters = data_array[:,2].reshape(-1, 1)
    Sell_price = data_array[:,3].reshape(-1, 1)
    
    figure, axis = plt.subplots(2, 3)
    
def plot_plot(axis, x1_title, i, j, data, target, continuous_data, continuous_predict, mse):
        axis[i,j].scatter(data, target, label = 'target')
        axis[i,j].plot(continuous_data, continuous_predict, label ='Predicted target')
        axis[i,j].set_xlabel(x1_title)
        axis[i,j].set_ylabel('y: target')
        axis[i,j].set_title(f"mse = {mse}")
        axis[i,j].legend()
    
def plot_scattered(axis, x1_title, i, j, data, target, predict):
    axis[i,j].scatter(data, target, label = 'target')
    axis[i,j].scatter(data, predict, label ='Predicted target')
    axis[i,j].set_xlabel(x1_title)
    axis[i,j].set_ylabel('y: target')
    axis[i,j].set_title(f"mse = {mse_(target, predict)}")
    axis[i,j].legend()

def chose_models(data, thetas, alpha, max_iter):
    data_train, data_test, nbr_train, nbr_test = data_splitter(data_array[:,1:], data_array[:,0], p)
    multi = data_train[:,0:3]
    weight = data_train[:,0].reshape(-1, 1)
    prod_distance = data_train[:,1].reshape(-1, 1)
    time_delivery = data_train[:,2].reshape(-1, 1)
    target = data_train[:,3].reshape(-1, 1)

    figure, axis = plt.subplots(4, 3)
    print("set up ok")
    print("training time") 
    for i in range (4):
        multi_poly = add_polynomial_features(multi, i + 1)
        print(f"set up {i} ok, now calculating theta...")
        print(multi_poly.shape, target.shape, thetas[i].shape)
        theta = fit_(multi_poly, target, thetas[i], alpha, max_iter)
        print(f"traning completed with teta = {theta}, now testing")
        
        multi_test = data_test[:,0:3]
        weight_test = data_test[:,0].reshape(-1, 1)
        prod_distance_test = data_test[:,1].reshape(-1, 1)
        time_delivery_test = data_test[:,2].reshape(-1, 1)
        target_test = data_test[:,3].reshape(-1, 1)

        multi_test_poly = add_polynomial_features(multi_test, i + 1)
        predict_target = predict(multi_test_poly, theta)
        print(f"done predicting {i}, now ploting")
        print(target_test.mean(), predict_target.mean())
        plot_scattered(axis, 'weight', i, 0, weight_test, target_test, predict_target)
        plot_scattered(axis, 'prod_distance', i, 1, prod_distance_test, target_test, predict_target)
        plot_scattered(axis, 'time_delivery', i, 2, time_delivery_test, target_test, predict_target)
        print(theta)
    plt.show()


if __name__ == '__main__':
    path = 'space_avocado.csv'
    with open(path, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
    data_array = np.array(data[1:], dtype = float)
    data = data_array[:,1:5]
    data_nbr = data_array[:,0]
    #print(multi)
    #print(Age, Thrust_power, Terameters, Sell_price)
    p = 0.75
    theta1 = np.array([[500000], [4111], [-385], [55501]]).reshape(-1, 1)
    theta2 = np.array([[500000], [4111], [-385], [55501], [21],[21],[21]]).reshape(-1, 1)
    theta2 = np.array([[500000], [4111], [-385], [55501], [21],[21],[21]]).reshape(-1, 1)
    theta3 = np.array([[500000], [4111], [-385], [55501], [21],[21],[21], [21],[21],[21]]).reshape(-1, 1)
    theta4 = np.array([[500000], [4111], [-385], [55501], [21],[21],[21],[21],[21],[21],[21],[21],[21]]).reshape(-1, 1)
    thetas = [theta1, theta2, theta3, theta4]
    alpha = 5e-20
    max_iter = 1000000
    chose_models(data, thetas, alpha, max_iter)
