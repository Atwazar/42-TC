# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thelaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:33:11 by thelaine          #+#    #+#              #
#    Updated: 2024/07/28 17:27:48 by thelaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FILES = main.c \
		game\
		garbage_collector\
		check_args\
		include\
		libft_spe\
		parsing\

SOURCES = main.c \
		./libft_spe/ft_calloc.c\
		./libft_spe/ft_putstr_fd.c\
		./libft_spe/ft_split.c\
		./libft_spe/ft_strlcpy.c\
		./libft_spe/ft_strlen.c\
		./libft_spe/ft_substr.c\
		./libft_spe/ft_putchar_fd.c\
		./libft_spe/ft_putnbr_fd.c\
		./libft_spe/ft_itoa.c\
		./libft_spe/ft_strjoin.c\
		./libft_spe/ft_strlcat.c\
		./libft_spe/ft_strcmp.c\
		./garbage_collector/memory_management.c\
		./check_args/check_args.c\
		./parsing/read_map.c \
		./parsing/map_error.c\
		./parsing/check_map.c \
		./parsing/dont_go_there.c\
		./parsing/check_map_doable.c\
		./game/game_error.c\
		./game/handle_keypress.c\
		./game/do_the_move.c\
		./game/create_sprites.c\
		./game/load_map.c\
		./game/game_init.c\
		./game/game_exit.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I /usr/local/include -I ./minilibx
LDFLAGS = -L /usr/local/lib -L libmlx_Linux -L ./minilibx
LIBS = -lmlx -lX11 -lXext -lm

# ---------------------------------- RULES ----------------------------------- #

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: minilibx $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJECTS)
	@$(MAKE) -C minilibx clean

fclean: clean
	rm -f $(NAME)

minilibx:
	$(MAKE) -C minilibx

re: fclean all

norm:
	norminette $(FILES)

.PHONY: all clean fclean re minilibx
