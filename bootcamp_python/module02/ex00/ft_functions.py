# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_functions.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 09:08:26 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 10:23:53 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def test(inti):
    inti += 20
    return (inti)

def test2(inti):
    return (inti > 2)

def test3(a, b):
    return (a + b)

def ft_map(function_to_apply, iterable):
    if not hasattr(iterable, '__iter__'):
        raise AttributeError("not the good type")
        return None
    try :
        for i in iterable:
            yield (function_to_apply(i))
    except :
        raise AttributeError("not the good type")


    """Map the function to all elements of the iterable.
    Args:
    function_to_apply: a function taking an iterable.
    iterable: an iterable object (list, tuple, iterator).
    Return:
    An iterable.
    None if the iterable can not be used by the function.
    """
def ft_filter(function_to_apply, iterable):
    if not hasattr(iterable, '__iter__'):
        raise AttributeError("not the good type")
        return None
    try:
        for i in iterable:
                if function_to_apply(i):
                    yield (i)
    except:
        raise AttributeError("not the good type")
    """Filter the result of function apply to all elements of the iterable.
    Args:
    function_to_apply: a function taking an iterable.
    iterable: an iterable object (list, tuple, iterator).
    Return:
    An iterable.
    None if the iterable can not be used by the function.
    """
def ft_reduce(function_to_apply, iterable):
    if not hasattr(iterable, '__iter__'):
        raise AttributeError("not the good type")
        return None
    value = 0
    try:
        value = iterable[0]
        for i in range(1, len(iterable)):
            value = function_to_apply(value, iterable[i])
        return value
    except:
        raise AttributeError("not the good type")
    """Apply function of two arguments cumulatively.
    Args:
    function_to_apply: a function taking an iterable.
    iterable: an iterable object (list, tuple, iterator).
    Return:
    A value, of same type of elements in the iterable parameter.
    None if the iterable can not be used by the function.
    """

if __name__ == '__main__':
    inti = (0, 1, 2 ,3, 5)
    print(inti)
    print(ft_map(test, inti))
    for j in ft_map(test, inti):
        print (j)
    print(ft_filter(test2, inti))
    for j in ft_filter(test2, inti):
        print (j)
    print(ft_reduce(test3, inti))
