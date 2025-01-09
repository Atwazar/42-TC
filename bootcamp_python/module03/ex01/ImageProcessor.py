# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ImageProcessor.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 09:57:17 by thelaine          #+#    #+#              #
#    Updated: 2024/06/14 11:11:22 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from PIL import Image
import matplotlib.pyplot as plt
import numpy as np

class ImageProcessor:
    def load(self, path):
        image_array = Image.open(path)
        image_array = np.array(image_array)
        print(f"loading {len(image_array)}x{len(image_array[0])}")
        return image_array
    def display(self, array):
        plt.imshow(array)
        plt.axis('off')
        plt.show()

class ScrapBooker:
    def crop(self, array, dim, position=(0,0)):
        array = array[position[0]:(dim[0]+position[0]), position[1]:(dim[1] + position[1])]
        #array = array[:(dim[0]+position[0]), :(dim[1] + position[1])]
        print(f"loading {len(array)}x{len(array[0])}")
        return array
    def thin(self, array, n, axis):
        if axis == 1:
            for i in range(len(array)//n):
                array = np.delete(array, i * n, axis)
        else:
            for i in range(len(array[0])//n):
                array = np.delete(array, i * n, axis)
        return array
    def juxtapose(self, array, n, axis):
        final_array = array
        for i in range(n - 1):
            final_array = np.concatenate((final_array, array), axis)
        return final_array
    def mosaic(self, array, dim):
        final_array = self.juxtapose(array, dim[0], 1)
        final_array = self.juxtapose(final_array, dim[1], 0)
        return final_array

class ColorFilter:
    def  invert(self, array):
        for i in range(len(array) - 1):
            for j in range(len(array[0]) - 1):
                r, g, b = array[i][j][0], array[i][j][1], array[i][j][2]
                array[i][j][0], array[i][j][1], array[i][j][2] = 255 - r, 255 - g, 255 - b
                #print(f"nous avons array[{i}][{j}] = {array[i][j]}")
        return (array)
    def to_blue(self, array):
        for i in range(len(array) - 1):
            for j in range(len(array[0]) - 1):
                r, g, b = array[i][j][0], array[i][j][1], array[i][j][2]
                array[i][j][0], array[i][j][1], array[i][j][2] = 0, 0, b
                #print(f"nous avons array[{i}][{j}] = {array[i][j]}")
        return (array)
    def to_green(self, array):
        for i in range(len(array) - 1):
            for j in range(len(array[0]) - 1):
                r, g, b = array[i][j][0], array[i][j][1], array[i][j][2]
                array[i][j][0], array[i][j][1], array[i][j][2] = 0, g, 0
                #print(f"nous avons array[{i}][{j}] = {array[i][j]}")
        return (array)
    def to_red(self, array):
        for i in range(len(array) - 1):
            for j in range(len(array[0]) - 1):
                r, g, b = array[i][j][0], array[i][j][1], array[i][j][2]
                array[i][j][0], array[i][j][1], array[i][j][2] = r, 0, 0
                #print(f"nous avons array[{i}][{j}] = {array[i][j]}")
        return (array)
    #def to_celluloid(self, array):
    def to_grayscale(self, array, filter, **kwargs):
        for i in range(len(array) - 1):
            for j in range(len(array[0]) - 1):
                r, g, b = array[i][j][0], array[i][j][1], array[i][j][2]
                if filter == 'mean' or filter == 'm':
                    array[i][j][3] = int((r + g + b)/3)
                elif filter == 'weigth' or filter == 'w':
                    array[i][j][3] = int(kwargs['weights'][0] * r +  kwargs['weights'][1] * g + kwargs['weights'][2] * b)
                #print(f"nous avons array[{i}][{j}] = {array[i][j]}")
        return (array)
        



if __name__ == '__main__':
    IP = ImageProcessor()
    SB = ScrapBooker()
    CF = ColorFilter()
    path = "elon.png"
    dim = (2, 5)
    position = (50, 50)
    axis = 1 
    n = 10
    array = IP.load(path)
    test = array[0][0]
    print(test[0])
    #array = SB.crop(array, dim)    
    #array = SB.thin(array, n, axis)    
    #array = SB.juxtapose(array, n, axis)    
    #array = SB.mosaic(array, dim)    
    #array = CF.invert(array) 
    #array = CF.to_blue(array) 
    #array = CF.to_green(array) 
    #array = CF.to_red(array) 
    array = CF.to_grayscale(array, 'w', weights = (0.2, 0.5, 0.3))    
    #print(array)
    display = IP.display(array)
     
