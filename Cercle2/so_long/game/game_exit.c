/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:57:13 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/26 10:57:26 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	player_death(t_var *var)
{
	ft_putstr_fd("You died, at least you died trying\n", 2);
	rage_quit(var);
}

static void	map_succes(t_var *var)
{
	ft_putstr_fd("you succeeded in ", 1);
	ft_putnbr_fd(var->move_nbr, 1);
	ft_putstr_fd(" moves, what a beast\n", 1);
	rage_quit(var);
}

void	check_end_game(t_var *var)
{
	var->was_exit = 1;
	if (var->open_exit)
		map_succes(var);
}

void	rage_quit(t_var *var)
{
	mlx_destroy_window(var->mlx, var->win);
	destroy_sprites(var);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	clear_garbage_and_exit(var);
}

int	rage_quited(t_var *var)
{
	rage_quit(var);
	return (1);
}
