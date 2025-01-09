# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Kmeans.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 13:40:36 by thelaine          #+#    #+#              #
#    Updated: 2024/06/14 16:43:24 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import numpy as np
import random
import csv
import matplotlib.pyplot as plt

class KmeansClustering:
    def __init__(self, max_iter=10, ncentroid=4):
        self.ncentroid = ncentroid # number of centroids
        self.max_iter = max_iter # number of max iterations to update the centroids
        self.centroids = [] # values of the centroids
    
    def L1distance(self, v1, v2):
        return np.linalg.norm(v1 - v2)
        
        """
        Run the K-means clustering algorithm.
        For the location of the initial centroids, random pick ncentroids from the dataset.
        Args:
        -----
        X: has to be an numpy.ndarray, a matrice of dimension m * n.
        Return:
        -------
        None.
        Raises:
        -------
        This function should not raise any Exception.
        """
    def fit(self, X):
        max_values = []
        for i in range(len(X[0])):
            max_value = np.max(X[:,i])
            min_value = np.min(X[:,i])
            max_values.append([min_value, max_value])
        for i in range (self.ncentroid):
            lst = []
            for j in range(len(max_values)):
                lst.append(random.uniform(max_values[j][0], max_values[j][1]))
            self.centroids.append(lst)
    def predict(self, X):
        self.fit(X)
        guess = np.full((1, len(X)), -1)
        fig = plt.figure()
        ax = fig.add_subplot(projection='3d')
        ax.scatter(X[:,1], X[:,2], X[:,0])
        ax.scatter(np.array(self.centroids)[:,1],np.array(self.centroids)[:,2], np.array(self.centroids)[:,0])
        ax.set_title("initialisation")

        for iteration in range (self.max_iter):
            #axis[1][iteration].scatter(X[1], X[2])
            #axis[1][iteration].set_title("osef")
            for data in range (len(X)):
                lst_min = [self.L1distance(X[data], centroid) for centroid in self.centroids]
                index_min = lst_min.index(np.min(lst_min))
                guess[0][data] = index_min
            if iteration < self.max_iter - 1:
                for i in range(self.ncentroid - 1):
                    member = [];
                    for data in range(len(X)):
                        if guess[0][data] == i:
                            member.append(X[data].tolist())
                    for j in range(len(self.centroids[i])):
                        #print(np.array(member)[:,j])
                        #print(self.centroids[i][j])
                        self.centroids[i][j] = np.mean(np.array(member)[:,j])
            #print(f"fin {iteration} iteration, guess = {guess[0]} centroid = {self.centroids}")
        fig = plt.figure()
        ax = fig.add_subplot(projection='3d')
        ax.scatter(X[:,1], X[:,2], X[:,0])
        ax.scatter(np.array(self.centroids)[:,1],np.array(self.centroids)[:,2], np.array(self.centroids)[:,0])
        ax.set_title("initialisation")
        plt.show()
        return guess
        """
        Predict from wich cluster each datapoint belongs to.
        Args:
        -----
        X: has to be an numpy.ndarray, a matrice of dimension m * n.
        Return:
        -------
        the prediction has a numpy.ndarray, a vector of dimension m * 1.
        Raises:
        -------
        This function should not raise any Exception.
        """
if __name__ == '__main__':
    KC = KmeansClustering(ncentroid = 4)
    with open('solar_system_census.csv', 'r') as f:
        reader = csv.reader(f)
        data = list(reader)
    data_array = np.array(data[1:], dtype = float)
    data_array = np.delete(data_array, 0, 1)
    print(KC.predict(data_array))
    #print(KC.L1distance(data_array[0], data_array[1]))



