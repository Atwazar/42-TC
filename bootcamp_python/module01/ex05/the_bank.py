# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    the_bank.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 15:04:22 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 17:20:58 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



class Account(object):
    ID_COUNT = 1
    def __init__(self, name, **kwargs):
        self.__dict__.update(kwargs)
        self.id = self.ID_COUNT
        Account.ID_COUNT += 1
        self.name = name
        if not hasattr(self, "value"):
            self.value = 0
        if self.value < 0:
            raise AttributeError("Attribute value cannot be negative.")
        if not isinstance(self.name, str):
            raise AttributeError("Attribute name must be a str object.")
    def transfer(self, amount):
        self.value += amount
    def check_account(self):
        if not isinstance(self, Account) or not isinstance(self.name, str):
            return False
        if not isinstance(self.id, int):
            return False
        if not isinstance(self.value, int) and not isinstance(self.value, float):
            return False
        if len(dir(self)) % 2 == 1:
            print("4")
            return False
        if self.name == None and self.id == None and self.value == None:
            print("1")
            return False
        for test in dir(self):
            if str(test[:1]) == "b" or str(test[:3]) == "zip" or str(test[:4]) == "addr":
                return False
        return True
          

class Bank:
    def __init__(self):
        self.accounts = []
    def add(self, new_account):
        if not isinstance(new_account, Account) or new_account in self.accounts:
            return False
        self.accounts.append(new_account)
        return True
    
    def transfer(self, origin, dest, amount):
        if not isinstance(origin, str) or not isinstance(dest, str) or not isinstance(amount, float):
            return False
        for account in self.accounts:
            if account.name == origin:
                    account_ori =  account
            if account.name == dest:
                    account_dest = account
        if not account_ori.check_account() or not account_dest.check_account() or amount < 0:
            print("ba")
            return False
        if origin == dest or amount == 0:
            print("ca")
            return True
        if account_ori.value > amount:
            account_ori.transfer(-amount)
            account_dest.transfer(amount)
        return True
    def fix_account(self, name):
        if not isinstance(name, str):
            return False
        for account in self.accounts:
            if account.name == name:
                return True
        return False
    def __str__(self):
        s = "what we have is \n"
        for account in self.accounts:
            s+="name :" + account.name +"    value :" + str(account.value)+ "\n"
        return s

if __name__ == '__main__':
    account1 = Account("Michel", value = 50)
    account2 = Account("jean", value = 2000000)
    babanks = Bank()
    print(babanks)
    babanks.add(account1)
    babanks.add(account2)
    print(babanks)
    babanks.transfer("Michel", "jean", 10.0)
    print(babanks)



