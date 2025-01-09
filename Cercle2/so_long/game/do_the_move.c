/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:50:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/26 10:51:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

static void	update_map(t_var *var, int move)
{
	char	**map;

	map = var->map;
	put_image(var, var->row, var->col, move);
}

int	can_do(int mouvement, t_var *var)
{
	if (mouvement == GO_UP)
	{
		if (dont_go(var->map, var->row - 1, var->col))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_DOWN)
	{
		if (dont_go(var->map, var->row + 1, var->col))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_LEFT)
	{
		if (dont_go(var->map, var->row, var->col - 1))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_RIGHT)
	{
		if (dont_go(var->map, var->row, var->col + 1))
			return (IS_DOABLE);
	}
	return (IS_NOT_DOABLE);
}

static void	open_the_gate(t_var *var)
{
	var->open_exit = 1;
	put_image(var, var->row_exit, var->col_exit, EXIT_2);
}

static void	write_move_number(t_var *var)
{
	char	*str;
	char	*nbr;

	str = "number of moves : ";
	nbr = ft_itoa(var->move_nbr, var);
	str = ft_strjoin(str, nbr, var);
	ft_free(nbr, var);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	load_first_row(var);
	mlx_string_put(var->mlx, var->win, 16, 16, 0X0FF0000, str);
}

void	do_the_move(int mouvement, t_var *var)
{
	var->move_nbr++;
	write_move_number(var);
	if (mouvement == GO_UP)
		var->row--;
	else if (mouvement == GO_DOWN)
		var->row++;
	else if (mouvement == GO_LEFT)
		var->col--;
	else if (mouvement == GO_RIGHT)
		var->col++;
	update_map(var, mouvement);
	if ((var->map)[var->row][var->col] == 'C')
	{
		var->coins--;
		if (!var->coins)
			open_the_gate(var);
	}
	if ((var->map)[var->row][var->col] == 'M')
		player_death(var);
	if ((var->map)[var->row][var->col] == 'E')
		check_end_game(var);
	(var->map)[var->row][var->col] = 'P';
}
