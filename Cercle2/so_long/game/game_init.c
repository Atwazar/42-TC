/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:35:43 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 11:36:02 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

static void	update_sprites(t_var *var)
{
	int		col;
	int		row;
	char	**map;

	map = var->map;
	col = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C' || map[row][col] == 'M')
				put_image_map(var, row, col);
			col++;
		}
		row++;
	}
	var->sprit_nbr = 1 - var->sprit_nbr;
}

static int	playing_the_game(t_var *var)
{
	update_sprites(var);
	usleep(100000);
	return (1);
}

static void	check_screen_size(t_var *var, int *width, int *height)
{
	mlx_get_screen_size(var->mlx, width, height);
	if ((var->len_ref * S) > *width || (var->height * S > *height))
	{
		free(var->mlx);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("map is to big for the screen", 2);
		ft_putstr_fd(", get a bigger screen\n", 2);
		clear_garbage_and_exit(var);
	}
	*width = (var->len_ref * S);
	*height = (var->height * S);
}

void	game_init(t_var *var)
{
	int	width;
	int	height;

	var->sprit_nbr = 0;
	var->was_exit = 0;
	var->open_exit = 0;
	var->move_nbr = 0;
	var->mlx = mlx_init();
	if (!var->mlx)
		mlx_creation_error(var);
	check_screen_size(var, &width, &height);
	create_sprites(var);
	var->win = mlx_new_window(var->mlx, width, height, "So long");
	if (!var->win)
	{
		free(var->mlx);
		window_creation_error(var);
	}
	load_map(var);
	mlx_hook(var->win, 2, 1, &handle_keypress, var);
	mlx_hook(var->win, 17, 0, &rage_quited, var);
	mlx_loop_hook(var->mlx, &playing_the_game, var);
	mlx_loop(var->mlx);
}
