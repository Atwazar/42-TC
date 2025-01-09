# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:59:24 by thelaine          #+#    #+#              #
#    Updated: 2024/06/02 16:49:47 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	ft_countnumber.c ft_printf.c ft_utils.c ft_writenumbers.c

OBJS = $(SRCS:.c=.o)

INCLUDES = ft_printf.h

RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a


${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} $(INCLUDES)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
