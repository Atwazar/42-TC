# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:09:55 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 11:41:02 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def what_are_the_vars(*args, **kwargs):
    return ObjectC(*args, **kwargs)

class ObjectC(object):
    def __init__(self, *args, **kwargs):
        i = 0
        check = 0
        for elem in kwargs:
            for j in range(len(args)):
                if elem == f"var_{j}":
                    print("ERROR")
                    check = 1
        if check == 0:
            for elem in kwargs:
                setattr(self, elem, kwargs[elem])
            for elem in args:
                setattr(self, f"var_{i}", elem)
                i+=1
    
def doom_printer(obj):
    if obj is None:
        print("ERROR")
        print("end")
        return
    for attr in dir(obj):
        if attr[0] != '_':
            value = getattr(obj, attr)
            print("{}: {}".format(attr, value))
    print("end")

if __name__ == "__main__":
    obj = what_are_the_vars(7)
    doom_printer(obj)
    obj = what_are_the_vars(None, [])
    doom_printer(obj)
    obj = what_are_the_vars("ft_lol", "Hi")
    doom_printer(obj)
    obj = what_are_the_vars()
    doom_printer(obj)
    obj = what_are_the_vars(12, "Yes", [0, 0, 0], a=10, hello="world")
    doom_printer(obj)
    obj = what_are_the_vars(42, a=10, var_0="world")
    doom_printer(obj)
    obj = what_are_the_vars(42, "Yes", a=10, var_2="world")
    doom_printer(obj)
