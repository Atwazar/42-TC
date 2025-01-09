# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    my_linear_regression.py                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 10:08:30 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 17:14:27 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class MyLinearRegression():
    
    def __init__(self, thetas, alpha=0.001, max_iter=1000):
        self.alpha = alpha
        self.max_iter = max_iter
        self.thetas = thetas
    
    def __gradient__(self, x, y):
        x = np.c_[np.ones(len(x)), x]
        return (np.dot(x.T, (np.dot(x, self.thetas) - y)))/len(x)

    def __fit_(self, x, y):
        for i in range(max_iter):
            self.thetas = self.thetas - alpha * self.gradient(x, y)
        return self.thetas

    def predict_(self, x):
        x_inter = np.c_[np.ones(len(x)), x]
        y_hat = np.dot(x_inter, self.thetas)
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
    
    def plot_with_loss(self, x, y, theta):
    plt.scatter(x, y)
    y_curv = predict_(x, theta)
    plt.plot(x, y_curv, color = 'red')
    plt.title(f"cost = {vect_loss_(y, y_curv)}")
    for i in range(len(y)):
        plt.plot([x[i],x[i]], [y[i], y_curv[i]], '--', color = "y")
    plt.show()



if __name__ == '__main__':
    x = np.array([[12.4956442], [21.5007972], [31.5527382], [48.9145838], [57.5088733]])
    y = np.array([[37.4013816], [36.1473236], [45.7655287], [46.6793434], [59.5585554]])
    theta =  np.array([[2], [0.7]])
    lr1 = MyLinearRegression(theta)
    y_hat = lr1.predict_(x)
    print(y_hat)
    print(lr1.loss_elem_(y, y_hat))
    print(lr1.loss_(y, y_hat))
