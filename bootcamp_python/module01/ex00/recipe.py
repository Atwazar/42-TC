# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 10:04:03 by thelaine          #+#    #+#              #
#    Updated: 2024/06/11 11:17:54 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cooking_lvls = [1,2,3,4,5]
recipe_types = ["starter", "lunch", "dessert"]

class Recipe:
    def __init__(self, name, cooking_lvl, cooking_time, ingredients, description, recipe_type):
        if isinstance(name, str) and name != "":
            self.name = name
        else:
            print("Wrong name entered")
            exit()
        if isinstance(cooking_lvl, int) and cooking_lvl in cooking_lvls:
            self.cooking_lvl = cooking_lvl
        else:
            print("Wrong cooking level entered")
            exit()
        if isinstance(cooking_time, int) and cooking_time >= 0:
            self.cooking_time = cooking_time
        else:
            print("Wrong cooking time entered")
            exit()
        if isinstance(ingredients, list) and ingredients != [] and [isinstance(ingredients, str) for ingredient in ingredients]:
            self.ingredients = ingredients
        else:
            print("Wrong ingredients entered")
            exit()
        if isinstance(description, str):
            self.description = description
        else:
            print("Wrong description entered")
            exit()
        if isinstance(recipe_type, str) and recipe_type in recipe_types:
            self.recipe_type = recipe_type
        else:
            print("Wrong recipe_type entered")
            exit()
    def __str__(self):
        string = ""
        string += "     Recipe for " + self.name + " to eat for " + self.recipe_type + "\n"
        string += "Recipe diffuculty : " + str(self.cooking_lvl) + "       " + "Cooking Time: " + str(self.cooking_time) + "\n"
        string += "Description :" + self.description + "\n"
        string += "List of ingredients : " + " ".join(self.ingredients)
        return (string)

if __name__ == "__main__":
    name = "tourte"
    cooking_lvl = 2
    cooking_time = 15
    ingredients = ["beurre", "sel"]
    description = "bah une tourte quoi"
    recipe_type = "lunch"
    recette1 = Recipe(name, cooking_lvl, cooking_time, ingredients, description, recipe_type)
    print(recette1)
