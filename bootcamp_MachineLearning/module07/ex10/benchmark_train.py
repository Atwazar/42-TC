# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    benchmark_train.py                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:44:33 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 15:35:44 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import csv
import matplotlib.pyplot as plt

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
    
def plot_scattered(axis, x1_title, i, j, data, target, predict, mse):
    axis[i,j].scatter(data, target, label = 'target')
    axis[i,j].scatter(data, predict_target, label ='Predicted target')
    axis[i,j].set_xlabel(x1_title)
    axis[i,j].set_ylabel('y: target')
    axis[i,j].set_title(f"mse = {mse}")
    axis[i,j].legend()

def chose_models(data, thetas, alpha, max_iter):
    multi = data_array[:,1:4]
    weight = data_array[:,1]
    continuous_weight = np.linspace(np.min(weight), np.max(weight), 1000)
    prod_distance = data_array[:,2]
    continuous_dist = np.linspace(np.min(prod_distance), np.max(prod_distance), 1000)
    time_delivery = data_array[:,3]
    continuous_time = np.linspace(np.min(time_delivery), np.max(time_delivery), 1000)
    continuous_multi = np.c_[continuous_weight, continuous_dist, continuous_time]
    target = data_array[:,4]

    figure, axis = plt.subplots(4, 3)
    print("set up ok")
    
    for i in range (1):
        multi_poly = add_polynomial_features(multi, i + 1)
        continuous_multi_poly = add_polynomial_features(continuous_multi, i + 1)
        print(f"set up {i} ok, now calculating theta...")
        theta = fit_(multi_poly, target, thetas[i], alpha, max_iter)
        print(theta.shape)
        print(f"done calculating theta{i}, now predicting")
        predict_theta = predict(continuous_multi_poly, theta)
        print(f"done predicting {i}, now ploting")
        plot_plot(axis, 'weight', i, 0, weight, target, continuous_weight, continuous_multi_poly[:,0], 'mse_(target, predict(weight, theta))')
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
    data_train, data_test, nbr_train, nbr_test = data_splitter(data, data_array[:,0], p)
    theta1 = np.array([[1000], [-1], [2], [3]])
    thetas = [theta1]
    alpha = 5e-10
    max_iter = 5000
    chose_models(data_train, thetas, alpha, max_iter)
