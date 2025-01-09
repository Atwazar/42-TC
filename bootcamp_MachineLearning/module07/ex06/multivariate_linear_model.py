# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    multivariate_linear_model.py                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:44:33 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 13:39:27 by thelaine         ###   ########.fr        #
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

def plot_graphs(data_array, theta, alpha, max_iter):
    
    Age = data_array[:,0].reshape(-1, 1)
    Thrust_power = data_array[:,1].reshape(-1, 1)
    Terameters = data_array[:,2].reshape(-1, 1)
    Sell_price = data_array[:,3].reshape(-1, 1)
    
    figure, axis = plt.subplots(2, 3)
    
    axis[0,0].scatter(Age, Sell_price, label = 'SellPrice')
    theta_age = fit_(Age, Sell_price, theta, alpha, max_iter)
    predict_age = predict(Age, theta_age)
    axis[0,0].scatter(Age, predict_age, label ='Predicted sell price')
    axis[0,0].set_xlabel('x1: age (in years)')
    axis[0,0].set_ylabel('y: sell price (in keuros)')
    axis[0,0].set_title(f"mse = {mse_(Sell_price, predict_age)}")
    axis[0,0].legend()

    print("age 1 ok")

    axis[0,1].scatter(Thrust_power, Sell_price, label = 'SellPrice')
    theta_thrust = fit_(Thrust_power, Sell_price, theta, alpha, max_iter)
    predict_thrust = predict(Thrust_power, theta_thrust)
    axis[0,1].scatter(Thrust_power, predict_thrust, label ='Predicted sell price')
    axis[0,1].set_xlabel('x2: thrust power (in 10Km/s)')
    axis[0,1].set_ylabel('y: sell price (in keuros)')
    axis[0,1].set_title(f"mse = {mse_(Sell_price, predict_thrust)}")
    axis[0,1].legend()

    print("thrust 1 ok")

    axis[0,2].scatter(Terameters, Sell_price, label = 'SellPrice')
    theta_tera = fit_(Terameters, Sell_price, theta, alpha, max_iter)
    predict_tera = predict(Terameters, theta_tera)
    axis[0,2].scatter(Terameters, predict_tera, label ='Predicted sell price')
    axis[0,2].set_xlabel('x3: distance totalizer value of spacecraft (in Tmeters)')
    axis[0,2].set_ylabel('y: sell price (in keuros)')
    axis[0,2].set_title(f"mse = {mse_(Sell_price, predict_tera)}")
    axis[0,2].legend()

    print("tera 1 ok")

    print("premiere partie ok")

    theta = np.array([[1.0],[1.0],[1.0],[1.0]]).reshape(-1, 1)
    alpha = 9e-5
    max_iter = 500000
    multi = data_array[:,0:3]
    theta_multi = fit_(multi, Sell_price, theta, alpha, max_iter)
    predict_multi = predict(multi, theta_multi)

    print("big boy ok")

    predict_age = predict_multi[:,0]
    predict_thrust = predict_multi[:,0]
    predict_tera = predict_multi[:,0]

    axis[1,0].scatter(Age, Sell_price, label = 'SellPrice')
    axis[1,0].scatter(Age, predict_age, label ='Predicted sell price')
    axis[1,0].set_xlabel('x1: age (in years)')
    axis[1,0].set_ylabel('y: sell price (in keuros)')
    axis[1,0].set_title(f"mse = {mse_(Sell_price, predict_age)}")
    axis[1,0].legend()

    axis[1,1].scatter(Thrust_power, Sell_price, label = 'SellPrice')
    axis[1,1].scatter(Thrust_power, predict_thrust, label ='Predicted sell price')
    axis[1,1].set_xlabel('x2: thrust power (in 10Km/s)')
    axis[1,1].set_ylabel('y: sell price (in keuros)')
    axis[1,1].set_title(f"mse = {mse_(Sell_price, predict_thrust)}")
    axis[1,1].legend()

    axis[1,2].scatter(Terameters, Sell_price, label = 'SellPrice')
    axis[1,2].scatter(Terameters, predict_tera, label ='Predicted sell price')
    axis[1,2].set_xlabel('x3: distance totalizer value of spacecraft (in Tmeters)')
    axis[1,2].set_ylabel('y: sell price (in keuros)')
    axis[1,2].set_title(f"mse = {mse_(Sell_price, predict_tera)}")
    axis[1,2].legend()
    plt.show()


if __name__ == '__main__':
    path = 'spacecraft_data.csv'
    with open(path, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
    data_array = np.array(data[1:], dtype = float)
    data = data_array[1:,1:]
    Age = data_array[:,0].reshape(-1, 1)
    Thrust_power = data_array[:,1].reshape(-1, 1)
    Terameters = data_array[:,2].reshape(-1, 1)
    Sell_price = data_array[:,3].reshape(-1, 1)
    multi = data_array[:,0:3]
    #print(multi)
    #print(Age, Thrust_power, Terameters, Sell_price)
    theta1 = np.array([[1000], [-1]])
    alpha = 2.5e-5
    max_iter = 200000
    plot_graphs(data_array, theta1, alpha, max_iter)
