# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 15:23:34 by thelaine          #+#    #+#              #
#    Updated: 2024/08/12 15:23:41 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

SOURCES =	main.cpp \
			ClapTrap.cpp \
			FragTrap.cpp \
			ScavTrap.cpp \
			DiamondTrap.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -Wshadow -std=c++98

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
