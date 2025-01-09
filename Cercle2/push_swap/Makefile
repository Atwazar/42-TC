# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:59:24 by thelaine          #+#    #+#              #
#    Updated: 2024/07/28 13:55:49 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = create_tablong.c ft_split.c utils_2.c \
       utils.c checks.c create_stack.c rotate.c rev_rotate.c \
	swap.c push.c short_sort.c find_quartile.c utils_3.c \
	pre_sort.c find_elem_place.c find_best_rotate.c \
	do_best_rotate.c sort.c utils_3.c push_swap.c

OBJS = $(SRCS:.c=.o)

BONUS = bonus/get_next_line_bonus.c bonus/push_swap_bonus.c \
       	bonus/rotate_bonus.c bonus/rev_rotate_bonus.c \
	bonus/push_bonus.c bonus/swap_bonus.c \
	bonus/get_next_line_utils.c bonus/ft_split_bonus.c\
	bonus/create_tablong_bonus.c bonus/create_stack_bonus.c\
	bonus/utils_bonus.c bonus/utils_2_bonus.c \
	bonus/utils_3_bonus.c bonus/checks_bonus.c\


BONUS_OBJS = $(BONUS:.c=.o)

INCLUDES = ft_push_swap.h

RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)
	
$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@ 

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME) $(BONUS_NAME)

bonus: all $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	cc $(CFLAGS) $^ -o $@

re: fclean all

.PHONY: all clean fclean re
