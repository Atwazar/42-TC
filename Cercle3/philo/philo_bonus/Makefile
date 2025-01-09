# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:33:11 by thelaine          #+#    #+#              #
#    Updated: 2024/08/08 14:00:20 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SOURCES =	philo_bonus.c \
			definitly_not_libft/ft_atoi.c\
			definitly_not_libft/ft_putchar_fd.c\
			definitly_not_libft/ft_putstr_fd.c\
			definitly_not_libft/ft_strlen.c\
			time_management/time_management_bonus.c\
			just_cleaning/just_cleaning_bonus.c\
			initialization/check_args_bonus.c\
			initialization/create_philo_table_bonus.c\
			initialization/create_philo_process_bonus.c\
			monitor/monitor_bonus.c\
			routine/routine_bonus.c\
			routine/speak_bonus.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L /usr/local/lib
LIBS = -pthread
INCLUDES = -I /usr/local/include

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean test fclean re
