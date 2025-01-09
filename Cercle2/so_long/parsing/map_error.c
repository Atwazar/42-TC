/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:06:25 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/27 20:27:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	dimension_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("map dimension error\n", 2);
	clear_garbage_and_exit(var);
}

void	border_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("there is a hole in the border\n", 2);
	clear_garbage_and_exit(var);
}

void	char_error(char unexpected, t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("there is an unexpected \'", 2);
	ft_putchar_fd(unexpected, 2);
	ft_putstr_fd("\' in the map\n", 2);
	clear_garbage_and_exit(var);
}

void	map_config_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	if (var->player != 1)
		ft_putstr_fd("Only one and one player only can be on the map\n", 2);
	if (var->exit != 1)
		ft_putstr_fd("Only one and one exit only can be on the map\n", 2);
	if (var->coins < 1)
		ft_putstr_fd("You need at least one coin to play the game !\n", 2);
	clear_garbage_and_exit(var);
}

void	map_not_doable_error(t_var *var)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Difficulty is great, but this is impossible\n", 2);
	clear_garbage_and_exit(var);
}
