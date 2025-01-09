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

NAME = Zombie

SOURCES =	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
