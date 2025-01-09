# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mono_log.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 11:37:37 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 13:49:39 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from my_logistic_regression import MyLogisticRegression as MyLR
from data_splitter import data_splitter
import matplotlib.pyplot as plt
from alive_progress import alive_bar
import csv

def one_vs_all(data_train, data_test,  target_train, target_test, planet, p, mylr):
    
    #print(len(data_array), len(data_train))
    target_earth_train, target_earth_test = np.zeros(target_train.shape), np.zeros(target_test.shape)
    
    for i in range(len(target_train)):
            target_earth_train[i] += target_train[i] == planet
    for i in range(len(target_test)):
            target_earth_test[i] += target_test[i] == planet
    #print(target_earth_train, target_train)
    
    weight_train = data_train[:,0]
    height_train = data_train[:,1]
    bone_density_train = data_train[:,2]
    weight_test = data_test[:,0]
    height_test = data_test[:,1]
    bone_density_test = data_test[:,2]
    

    theta_opt = mylr.fit_(data_train, target_earth_train)
    y_hat = mylr.logistic_predict_(data_test)
    #figure, axis = plt.subplots(1, 3)
    #mylr.plot_scattered(axis, 'Weight', 0, weight_test, target_earth_test, y_hat)
    #mylr.plot_scattered(axis, 'Height', 1, height_test, target_earth_test, y_hat)
    #mylr.plot_scattered(axis, 'Bone density', 2, bone_density_test, target_earth_test, y_hat)
    return y_hat

if __name__ == '__main__':
    path1 = 'solar_system_census.csv'
    path2 = 'solar_system_census_planets.csv'
    p = 0.8
    theta1 =  np.array([[2], [0.5], [7.1], [4.3]]).reshape(-1, 1)
    alpha = 0.005
    max_iter = 100000
    mylr = MyLR(theta1, alpha = alpha, max_iter = max_iter)
    planet = 1

    with open(path1, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
        data_array = np.array(data[1:], dtype = float)[:,1:]
    
    with open(path2, 'r') as f:
        reader = csv.reader(f)
        target = list(reader)
        target_array = np.array(target[1:], dtype = float)[:,1:].reshape(-1, 1)
    #print(data_array, target_array)
    data_train, data_test, target_train, target_test = data_splitter(data_array, target_array, p)
    one_vs_all(data_train, data_test, target_train, target_test, planet, p, mylr) 
    plt.show()
