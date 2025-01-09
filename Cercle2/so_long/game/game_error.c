/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:30:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

void	mlx_creation_error(t_var *var)
{
	ft_putstr_fd("Error\ncritical failure during mlx init\n", 2);
	clear_garbage_and_exit(var);
}

void	window_creation_error(t_var *var)
{
	int	i;

	i = 0;
	destroy_sprites(var);
	ft_putstr_fd("Error\ncritical failure during window creation\n", 2);
	clear_garbage_and_exit(var);
}
