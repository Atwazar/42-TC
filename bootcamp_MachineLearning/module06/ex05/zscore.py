# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    zscore.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 12:16:40 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 13:03:29 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def zscore(x):
    mean = np.mean(x)
    std = np.std(x)
    xprime = []
    for i in range(len(x)):
        xprime.append(float((x[i] - mean)/std))
    return np.array([xprime])

def minmax(x):
    mini = np.min(x)
    maxi = np.max(x)
    xprime = []
    for i in range(len(x)):
        xprime.append(float((x[i] - mini)/(maxi - mini)))
    return np.array([xprime])

if __name__ == '__main__':
    X = np.array([0, 15, -9, 7, 12, 3, -21])
    print(zscore(X))
    print(minmax(X))

