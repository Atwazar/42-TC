# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 12:35:22 by thelaine          #+#    #+#              #
#    Updated: 2024/08/26 12:35:23 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SOURCES =	main.cpp \
			Animal.cpp\
			Cat.cpp \
			Dog.cpp\
			WrongAnimal.cpp\
			WrongCat.cpp


OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# ---------------------------------- RULES ----------------------------------- #

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
