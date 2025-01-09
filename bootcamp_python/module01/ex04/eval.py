# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    eval.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:43:46 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 15:01:23 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Evaluator:
    def zip_evaluate(coefs, words):
        if len(coefs) != len(words):
            return -1
        result = zip(coefs, words)
        summ = 0 
        for tuple in result:
            summ += tuple[0] * len(tuple[1])
        return summ
    def enumerate_evaluate(coefs, words):
        if len(coefs) != len(words):
            return -1
        result = enumerate(words)
        summ = 0 
        for i, word in result:
            summ += coefs[i] * len(word)
        return summ

if __name__ == '__main__':
    coefs = [1,2,3,4]
    words = ["bonjour", "comment", "ca", "va"]
    a = Evaluator.zip_evaluate(coefs, words)
    print(a)
    a = Evaluator.enumerate_evaluate(coefs, words)
    print(a)
