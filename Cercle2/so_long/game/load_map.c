/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:49:42 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/26 09:49:56 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	put_image(t_var *var, int row, int col, int type)
{
	void	*mlx;
	void	*win;

	mlx = var->mlx;
	win = var->win;
	row = row * S;
	col = col * S;
	mlx_put_image_to_window(mlx, win, var->sprites[type], col, row);
}

void	put_image_map(t_var *var, int row, int col)
{
	int	type;

	type = 0;
	if (var->map[row][col] == '0')
		type = EMPTY;
	else if (var->map[row][col] == '1')
		type = FULL;
	else if (var->map[row][col] == 'P')
		type = GO_DOWN;
	else if (var->map[row][col] == 'C')
		type = COINS_1 + var->sprit_nbr;
	else if (var->map[row][col] == 'E')
		type = EXIT_1;
	else if (var->map[row][col] == 'M')
		type = MONSTER_1 + var->sprit_nbr;
	put_image(var, row, col, type);
}

void	load_first_row(t_var *var)
{
	int	col;

	col = 0;
	while (var->map[FIRST_ROW][col])
	{
		put_image_map(var, FIRST_ROW, col);
			col++;
	}
}

void	load_map(t_var *var)
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
			put_image_map(var, row, col);
			col++;
		}
		row++;
	}
}
