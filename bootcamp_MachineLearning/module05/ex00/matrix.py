# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    matrix.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 09:37:49 by thelaine          #+#    #+#              #
#    Updated: 2024/06/17 11:02:42 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Matrix:
    def __init__(self, data=[], shape=0):
        if shape == 0:
            self.matrix = data
            self.shape = (len(data), len(data[0]))
        elif data == []:
            self.shape = shape
            self.matrix = data
            for i in range(self.shape[0]):
                self.matrix.append([0 for j in range(self.shape[1])])
   
    def __add__(self, other):
        if self.shape == other.shape:
            result = Matrix(shape = self.shape)
            for i in range(self.shape[0]):
                for j in range(self.shape[1]):
                    result.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]
        return result    
    
    def __sub__(self, other):
        if self.shape == other.shape:
            result = Matrix(shape = self.shape)
            for i in range(self.shape[0]):
                for j in range(self.shape[1]):
                    result.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]
        return result    
    
    def __truediv__(self, scalar):
        if (isinstance(scalar, int) or isinstance(scalar, float)) and scalar != 0:
            result = Matrix(shape = self.shape)
            for i in range(self.shape[0]):
                for j in range(self.shape[1]):
                    result.matrix[i][j] = self.matrix[i][j] / scalar
        return result    

    def __mul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            result = Matrix(shape = self.shape)
            for i in range(self.shape[0]):
                for j in range(self.shape[1]):
                    result.matrix[i][j] = self.matrix[i][j] * other
            return result    
        elif isinstance(other, Matrix) and self.shape[1] == other.shape[0]:
            result = Matrix(shape = (self.shape[0], other.shape[1]))
            for i in range(result.shape[0]):
                for j in range(result.shape[1]):
                    index = 0
                    for k in range (self.shape[1]):
                        index += self.matrix[i][k] * other.matrix[k][j]
                    result.matrix[i][j] = index
            return result

    def T(self):
            result = Matrix(shape = (self.shape[1], self.shape[0]))
            for i in range(result.shape[0]):
                for j in range(result.shape[1]):
                    result.matrix[i][j] = self.matrix[j][i]
            return result    

    def __str__(self):
        return (f"matrix of shape {str(self.shape)}=\n{str(self.matrix)}")

class Vector(Matrix):
    pass


if __name__ == '__main__':
    data = [[0, 1], [2, 3], [4, 5]]
    data2 = [[0, 1], [2, 3], [4, 5]]
    data3 = [[2, 3, 4], [5, 6, 7]]
    shape = (3, 2)
    scalar = 3
    m1 = Matrix(data)
    m2 = Matrix(data2)
    m3 = Matrix(data3)
    #print(m1)
    #print(m1 + m2)
    #print(m1 - m2)
    #print(m1 * scalar)
    #print(m1 / scalar)
    print(m1 * m3)
    #print(m1.T())
   
