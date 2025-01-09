# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:13:13 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 14:41:11 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import string as s
import random

def generator(text, sep, option = None):
    list_word = text.split(sep)
    if option == "shuffle" :
        result= []
        while len(list_word) > 0:
            i = random.randint(0, len(list_word) - 1)
            result.append(list_word.pop(i))
        list_word = result
    if option == "unique" :
        result = []
        [result.append(word) for word in list_word if word not in result]
        list_word = result
    if option == "ordered":
        list_word.sort()
    for words in list_word:
        yield (words)

if __name__ == '__main__':
    text = "Le Lorem Ipsum est simplement du faux texte texte";
    for word in generator(text, sep=" ", option="unique"):
         print(word)
    print(generator(text, sep =" ", option="unique").__dict__)

