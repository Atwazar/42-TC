# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    book.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 11:09:17 by thelaine          #+#    #+#              #
#    Updated: 2024/06/12 11:50:42 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from recipe import Recipe
import datetime


class Book:
    def __init__(self, name):
        recipe_list = {"starter" : [], "lunch" : [recette1], "dessert" :[]}
        creation_date = datetime.datetime.now().date()
        last_update = creation_date
        if isinstance(name, str) and name != "":
            self.name = name
        else:
            print("Wrong name entered")
            exit()
        self.last_update = last_update
        self.creation_date = creation_date
        self.recipe_list = recipe_list
    
    def get_recipe_by_name(self, name):
        for key, value in self.recipe_list.items():
            for recipe in value:
                if name == recipe.name:
                    print(recipe)
    def get_recipes_by_types(self, recipe_type):
        for key, value in self.recipe_list.items():
            if key == recipe_type:
                for recipe in value:
                    print(recipe)
    def add_recipe(self, recipe):
        for key, value in self.recipe_list.items():
            if key == recipe.recipe_type:
                value.append(recipe)
            book.last_update = datetime.datetime.now().date()




if __name__ == "__main__":
    name = "tourte"
    cooking_lvl = 2
    cooking_time = 15
    ingredients = ["beurre", "sel"]
    description = "bah une tourte quoi"
    recipe_type = "lunch"
    recette1 = Recipe(name, cooking_lvl, cooking_time, ingredients, description, recipe_type)
    print(recette1)

    name = "bokin"
    print(isinstance(type(datetime.datetime.now().date()), datetime.date))
    book = Book(name)
    print(book.name)
    print(book.last_update)
    print(book.creation_date)
    print(book.recipe_list["lunch"][0])
    book.get_recipe_by_name("tourte")
    book.get_recipes_by_types("lunch")
