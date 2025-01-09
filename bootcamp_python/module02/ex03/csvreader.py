# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    csvreader.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 12:30:46 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 14:19:06 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string

class CsvReader():
    def __init__(self, filename=None, sep= ',', header=False, skip_top=0, skip_bottom=0):
        self.file  = open(filename)
        self.filename = filename
        self.sep = sep
        self.header = header
        self.skip_top = skip_top
        self.skip_bottom = skip_bottom
    def __enter__(self):
        self.data =  self.file.read()
        stockage = self.data.split('\n')
        length = stockage[0].split(self.sep)
        stock =  []
        for i in range (len(stockage)):
            stock.append(stockage[i].split(self.sep))
            if len(stock[i]) != length:
                return None
        self.stockage = stock        
        return self.file
    def __exit__(self, type, value, traceback):
        self.file.close()
    def getdata(self):
        result = []
        for i in range (self.skip_top, len(stock) - 1 - self.skip_bottom):
            result.append(self.stockage[i])
        return result
        """ Retrieves the data/records from skip_top to skip bottom.
        Return:
        nested list (list(list, list, ...)) representing the data.
        """
        # ... Your code here ...
    def getheader(self):
        if self.header:
           return self.stockage[0]
             

        """ Retrieves the header from csv file.
        Returns:
        list: representing the data (when self.header is True).
        None: (when self.header is False).
        """
        # ... Your code here ...

with CsvReader('demo.txt') as opened_file:
    print("hello")
    if opened_file == None:
        print("todo es ok")
    print(opened_file.getdata())
    print(type(obj))
    print(CsvReader.getheader(obj))
    print(obj.sep)
