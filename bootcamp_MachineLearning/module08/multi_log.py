# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    multi_log.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 13:13:58 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 15:07:01 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from my_logistic_regression import MyLogisticRegression as MyLR
from data_splitter import data_splitter
import matplotlib.pyplot as plt
from alive_progress import alive_bar
import csv
from mono_log import one_vs_all

if __name__ == '__main__':
    path1 = 'solar_system_census.csv'
    path2 = 'solar_system_census_planets.csv'
    p = 0.8
    theta1 =  np.array([[2], [0.5], [7.1], [4.3]]).reshape(-1, 1)
    alpha = 0.005
    max_iter = 1000000
    mylr = MyLR(theta1, alpha = alpha, max_iter = max_iter)
    planet = [0, 1, 2, 3]
    with open(path1, 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
        data_array = np.array(data[1:], dtype = float)[:,1:]

    with open(path2, 'r') as f:
        reader = csv.reader(f)
        target = list(reader)
        target_array = np.array(target[1:], dtype = float)[:,1:].reshape(-1, 1)
    data_train, data_test, target_train, target_test = data_splitter(data_array, target_array, p)
    
    y_hats = 0
    for planeto in planet :
        print(f"calculating y_hat for planet {planeto})")
        y_hat = one_vs_all(data_train, data_test, target_train, target_test, planeto, p, mylr)
        if isinstance(y_hats, int):
            y_hats = y_hat
        else :
            y_hats = np.c_[y_hats, y_hat]
    y_hat_def = np.zeros(y_hat.shape)
    
    print("done calculating, now compiling results...")
    for i in range(len(y_hat_def)):
        maxo = np.max(y_hats[i])
        for j in planet:
            if maxo == y_hats[i][j]:
                y_hat_def[i] = j
    
    weight_train = data_train[:,0]
    height_train = data_train[:,1]
    bone_density_train = data_train[:,2]
    weight_test = data_test[:,0]
    height_test = data_test[:,1]
    bone_density_test = data_test[:,2]
    
    figure, axis = plt.subplots(1, 3)
    mylr.plot_scattered(axis, 'Weight', 0, weight_test, target_test, y_hat_def)
    mylr.plot_scattered(axis, 'Height', 1, height_test, target_test, y_hat_def)
    mylr.plot_scattered(axis, 'Bone density', 2, bone_density_test, target_test, y_hat_def)
    plt.show()
