# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    TinyStatistician.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 14:58:58 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 16:04:25 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import math

class TinyStatistician:
    
    def check(self, x):
        if not isinstance(x, list) or len(x) == 0:
            return False
        for elem in x:
            if not isinstance(elem, int) and not isinstance(elem, float):
                return False
        return True

    def mean(self, x):
        if not self.check(x):
            return None
        mean = 0
        for i in x:
            mean += i
        return (mean/len(x))
    
    def median(self, x):
        if not self.check(x):
            return None
        x.sort()
        if len(x)%2 == 1:
            return x[len(x)//2]
        else:
           return (x[(len(x) - 1)//2] + x[len(x)//2])/2
    def quartiles(self, x):
        if not self.check(x):
            return None
        x.sort()
        q1 = x[len(x)//4]
        pos_q3 = int(len(x)/4 * 3)
        q3 = x[pos_q3]
        return (q1,q3)
    def var(self, x):
        if not self.check(x):
            return None
        mean = self.mean(x)
        length = len(x)
        var = 0
        for y in x:
            var += (y - mean)*(y - mean)
        var = var/length
        return var
    def std(self, x):
        if not self.check(x):
            return None
        return (math.sqrt(self.var(x)))

if __name__=='__main__':
    print (3//2)
    ts = TinyStatistician()
    a = [1, 42, 300, 10, 59]
    print(ts.mean(a))
    #Expected result: 82.4
    print(ts.median(a))
    # Expected result: 42.0
    print(ts.quartiles(a))
    # Expected result: 42.0
    print(ts.var(a))
    # Expected result: 42.0
    print(ts.std(a))
    # Expected result: 42.0

