# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    polynomial_train.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 16:44:33 by thelaine          #+#    #+#              #
#    Updated: 2024/06/19 18:19:20 by thelaine         ###   ########.fr        #
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

def plot_graphs(data_array, alpha, max_iter):
    
    Micro = data_array[:,1].reshape(-1, 1)
    continuous_micro = np.arange(np.min(Micro), np.max(Micro), 0.01)
    Score = data_array[:,2].reshape(-1, 1)
    theta1 = np.array([[10], [34]]).reshape(-1,1)
    theta2 = np.array([[10], [34], [22]]).reshape(-1,1)
    theta3 = np.array([[10], [34], [22],[32]]).reshape(-1,1)
    theta4 = np.array([[-20], [160], [-80], [10], [-1]]).reshape(-1,1)
    theta5 = np.array([[1140], [-1850], [1110],[-305], [40],[-2]]).reshape(-1,1)
    theta6 = np.array([[9110], [-18015], [13400],[-4935], [966],[-96.4],[3.86]]).reshape(-1,1)
    thetas = [theta1, theta2, theta3, theta4, theta5, theta6]
    figure, axis = plt.subplots(2, 3)
    print("set up ok")

    for i in range(6):
        
        axis[i//3, i%3].scatter(Micro, Score, label = 'Score', color ='r')
        Micro_poly = add_polynomial_features(Micro, i + 1)
        continuous_micro_poly = add_polynomial_features(continuous_micro, i + 1)
        print(f"set up {i} ok")
        print(f"now calculating theta{i}")
        print(Micro_poly.shape, Score.shape, thetas[i].shape)
        theta = fit_(Micro_poly, Score, thetas[i], alpha, max_iter)
        print(f"theta shape = {theta.shape}")
        print(f"done calculating theta{i}")
        print(f"now making prediction")
        predict_theta = predict(continuous_micro_poly, theta)
        print(f"prediction{i} finished, now ploting")
        axis[i//3,i%3].plot(continuous_micro, predict_theta, label ='Predicted Score')
        axis[i//3,i%3].set_xlabel('x: Micrograms')
        axis[i//3,i%3].set_ylabel('y: Score')
        axis[i//3,i%3].set_title(f"tethai{i}: mse = {mse_(Score, predict(Micro_poly, theta))}")
        axis[i//3,i%3].legend()
        print(f"poly{i} ok")
    plt.show()

    #axis[0,0].scatter(Micro, Score, label = 'Score')
    #theta1 = fit_(Micro, Score, theta1, alpha, max_iter)
    #predict_theta1 = predict(continuous_micro, theta1)
    #axis[0,0].plot(continuous_micro, predict_theta1, label ='Predicted Score')
    #axis[0,0].set_xlabel('x: Micrograms')
    #axis[0,0].set_ylabel('y: Score')
    #axis[0,0].set_title(f"tetha 1: mse = {mse_(Score, predict(Micro, theta1))}")
    #axis[0,0].legend()
    

    #continuous_micro2 = add_polynomial_features(np.arange(np.min(Micro), np.max(Micro), 0.01), 2)
    #axis[0,1].scatter(Micro, Score, label = 'Score')
    #Micro2 = add_polynomial_features(Micro, 2)
    #theta2 = fit_(Micro2, Score, theta2, alpha, max_iter)
    #predict_theta2 = predict(continuous_micro2, theta2)
    #axis[0,1].plot(continuous_micro, predict_theta2, label ='Predicted Score')
    #axis[0,1].set_xlabel('x: Micrograms')
    #axis[0,1].set_ylabel('y: Score')
    #axis[0,1].set_title(f"tetha 2: mse = {mse_(Score, predict(Micro2, theta2))}")
    #axis[0,1].legend()

if __name__ == '__main__':
    path = 'are_blue_pills_magics.csv'
    with open(path, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
    data_array = np.array(data[1:], dtype = float)
    data = data_array[1:,1:]
    #print(multi)
    #print(Age, Thrust_power, Terameters, Sell_price)
    alpha = 1e-5
    max_iter = 1000
    plot_graphs(data_array, alpha, max_iter)
