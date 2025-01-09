# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:26:32 by thelaine          #+#    #+#              #
#    Updated: 2024/06/18 15:50:36 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c utils.c
OBJECTS = $(SOURCES:.c=.o)

INCLUDES = minitalk.h
all: server client


server: server.o utils.o
	$(CC) -o $@ $^

client: client.o utils.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	
	
fclean: clean
	rm -f server client

re: fclean all

bonus: server client

.PHONY: all bonus clean fclean re

