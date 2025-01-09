# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 12:35:22 by thelaine          #+#    #+#              #
#    Updated: 2024/09/22 17:38:03 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Identifier

SOURCES =	main.cpp \
			Base.cpp\
			A.cpp\
			B.cpp\
			C.cpp

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
