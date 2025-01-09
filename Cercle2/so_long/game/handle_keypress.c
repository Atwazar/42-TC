/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:33:19 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/22 17:33:34 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

static void	handle_mouvement(int mouvement, t_var *var)
{
	if (can_do(mouvement, var))
	{
		if (var->was_exit)
		{
			put_image(var, var->row, var->col, EXIT_1);
			var->was_exit = 0;
			(var->map)[var->row][var->col] = 'E';
		}
		else
		{
			put_image(var, var->row, var->col, EMPTY);
			(var->map)[var->row][var->col] = '0';
		}
		do_the_move(mouvement, var);
	}
}

static void	handle_escape(t_var *var)
{
	ft_putstr_fd("Exiting the program\n", 1);
	rage_quit(var);
}

int	handle_keypress(int keysym, t_var *var)
{
	if (keysym == XK_Escape)
		handle_escape(var);
	if (keysym == XK_Up)
		handle_mouvement(GO_UP, var);
	if (keysym == XK_Down)
		handle_mouvement(GO_DOWN, var);
	if (keysym == XK_Left)
		handle_mouvement(GO_LEFT, var);
	if (keysym == XK_Right)
		handle_mouvement(GO_RIGHT, var);
	return (1);
}
