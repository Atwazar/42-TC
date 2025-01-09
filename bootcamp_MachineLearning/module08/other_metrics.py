# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    other_metrics.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:08:40 by thelaine          #+#    #+#              #
#    Updated: 2024/06/20 15:43:35 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
import numpy as np

def find_unknown(y, y_hat):
        tp, tn, fp, fn = 0,0,0,0  
        value = np.unique(y)
        print(value)
        for i in range(len(y)):
            if y[i] == value[0]:
                if y_hat[i] == value[0]:
                    tp+=1
                else:
                    fp+=1
            else:
                if y_hat[i] == value[1]:
                    tn+=1
                else:
                    fn+=1
        return tp, tn, fp, fn

def accuracy_score_(y, y_hat):
    acc_score = 0
    for i in range(len(y)):
        if y[i] == y_hat[i]:
            acc_score+=1
    return acc_score/len(y)

def recall_score_(y, y_hat, pos_label=1):
    tp = 0
    fp = 0
    for i in range(len(y)):
        if y[i] == pos_label:
            if y[i] == y_hat[i]:
                tp+=1
            else:
                fp+=1
    return tp/(tp + fp)

def precision_score_(y, y_hat, pos_label=1):
    tp = 0
    fn = 0
    for i in range(len(y)):
        if y_hat[i] == pos_label:
            if y_hat[i] == y[i]:
                tp += 1
            else:
                fn += 1
    return tp/(tp + fn)

def f1_score_(y, y_hat, pos_label=1):
    precision = precision_score_(y, y_hat, pos_label)
    recall = recall_score_(y, y_hat, pos_label)
    return (2 * precision * recall)/(precision + recall)


y_hat = np.array([1, 1, 0, 1, 0, 0, 1, 1]).reshape((-1, 1))
y = np.array([1, 0, 0, 1, 0, 1, 0, 0]).reshape((-1, 1))
print(accuracy_score_(y, y_hat))
print(precision_score_(y, y_hat))
print(recall_score_(y, y_hat))
print(f1_score_(y, y_hat))

y_hat = np.array(['norminet', 'dog', 'norminet', 'norminet', 'dog', 'dog', 'dog', 'dog'])
y = np.array(['dog', 'dog', 'norminet', 'norminet', 'dog', 'norminet', 'dog', 'norminet'])
print(accuracy_score_(y, y_hat))
print(precision_score_(y, y_hat, 'dog'))
print(recall_score_(y, y_hat,'dog'))
print(f1_score_(y, y_hat,'dog'))

