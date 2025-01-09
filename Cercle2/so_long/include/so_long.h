/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:57:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:42:39 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define GO_UP 0
# define GO_DOWN 1
# define GO_LEFT 2
# define GO_RIGHT 3
# define NUMBER_OF_MOUV 4

# define EMPTY 4
# define FULL 5
# define EXIT_1 6
# define EXIT_2 7
# define COINS_1 8
# define COINS_2 9
# define MONSTER_1 10
# define MONSTER_2 11
# define NBR_OF_SPRITES 12

# define FIRST_ROW 0

# define IS_DOABLE 1
# define IS_NOT_DOABLE 0

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define FIRST_ANIME 0
# define SECOND_ANIME 1

# define S 32

typedef struct s_anime
{
	char			*path;
	struct s_anime	*next;
}	t_anime;

typedef struct s_garbage
{
	void				*content;
	struct s_garbage	*next;
}	t_garbage;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player_info {
	int		row;
	int		col;
	int		exit_left;
	int		coins_left;
	char	**map;
}	t_player_info;

typedef struct s_var {
	t_data			data;
	t_garbage		*garbage_collector;
	t_player_info	player_info;
	char			*path;
	char			*map_unsplit;
	char			**map;
	int				player;
	int				exit;
	int				coins;
	int				len_ref;
	int				height;
	void			*mlx;
	void			*win;
	char			**file;
	void			**sprites;
	int				row;
	int				col;
	int				row_exit;
	int				col_exit;
	int				was_exit;
	int				sprit_nbr;
	int				open_exit;
	int				move_nbr;
}	t_var;

//read_map.c
void	no_map_error(t_var *var);
void	read_file(t_var *var);

//map_error.c
void	dimension_error(t_var *var);
void	border_error(t_var *var);
void	char_error(char unexpected, t_var *var);
void	map_config_error(t_var *var);
void	map_not_doable_error(t_var *var);

//check_map.c
void	check_map(t_var *var);

//dont_go_there.c
int		dont_pars(char **map, int row, int col);
int		dont_go(char **map, int row, int col);

//check_map_doable.c
void	check_map_doable(t_var *var);

//libft_spe
void	*ft_calloc(int nb_elem, int size_elem, t_var *var);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *s, char c, t_var *var);
int		ft_strlcpy(char *dest, const char *src, int n);
int		ft_strlen(const char *str);
char	*ft_substr(char const *str, int start, int len, t_var *var);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n, t_var *var);
char	*ft_strjoin(char *s1, char *s2, t_var *var);
int		ft_strlcat(char *dest, const char *src, int n);
int		ft_strcmp(char *str1, char *str2);

//check_args.c
void	check_args(int ac, char **av, char **envp);

//garbage management
void	ft_free(void *content_to_find, t_var *var);
void	clear_garbage_and_exit(t_var *var);
void	*ft_malloc(int size, t_var *pvar);

//game_error.c
void	mlx_creation_error(t_var *var);
void	window_creation_error(t_var *var);

//create_sprites.c
void	create_sprites(t_var *var);
void	destroy_sprites(t_var *var);

//load_map.c
void	put_image(t_var *var, int row, int col, int type);
void	put_image_map(t_var *var, int row, int col);
void	load_first_row(t_var *var);
void	load_map(t_var *var);

//game_init.c
void	game_init(t_var *var);
void	test_print_map(t_var *var);//to delete;

//do_the_move.c
int		can_do(int mouvement, t_var *var);
void	do_the_move(int move, t_var *var);

//handle_keypress.c
int		handle_keypress(int keysym, t_var *var);

//game_exit.c
void	rage_quit(t_var *var);
int		rage_quited(t_var *var);
void	player_death(t_var *var);
void	check_end_game(t_var *var);

#endif
