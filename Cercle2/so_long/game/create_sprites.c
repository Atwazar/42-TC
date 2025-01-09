/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:51:27 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/24 17:51:46 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_path(t_var *var)
{
	var->file = ft_malloc(NBR_OF_SPRITES * sizeof(char *), var);
	var->file[GO_UP] = "./srcs/player_up.xpm";
	var->file[GO_DOWN] = "./srcs/player_down.xpm";
	var->file[GO_LEFT] = "./srcs/player_left.xpm";
	var->file[GO_RIGHT] = "./srcs/player_right.xpm";
	var->file[EMPTY] = "./srcs/empty.xpm";
	var->file[FULL] = "./srcs/full.xpm";
	var->file[EXIT_1] = "./srcs/exit_close.xpm";
	var->file[EXIT_2] = "./srcs/exit_open.xpm";
	var->file[COINS_1] = "./srcs/coins_1.xpm";
	var->file[COINS_2] = "./srcs/coins_2.xpm";
	var->file[MONSTER_1] = "./srcs/monster_1.xpm";
	var->file[MONSTER_2] = "./srcs/monster_2.xpm";
}

void	create_sprites(t_var *var)
{
	int	i;
	int	d;

	d = 32;
	i = 0;
	init_path(var);
	var->sprites = ft_malloc(NBR_OF_SPRITES * sizeof(void *), var);
	while (i < NBR_OF_SPRITES)
	{
		var->sprites[i] = mlx_xpm_file_to_image(var->mlx, var->file[i], &d, &d);
		if (!var->sprites[i])
		{
			d = 0;
			while (d < i)
				mlx_destroy_image(var->mlx, var->sprites[d++]);
			mlx_destroy_display(var->mlx);
			free(var->mlx);
			ft_putstr_fd("error during the conversion of xpm files\n", 2);
			clear_garbage_and_exit(var);
		}
		i++;
	}
}

void	destroy_sprites(t_var *var)
{
	int	i;

	i = 0;
	while (i < NBR_OF_SPRITES)
		mlx_destroy_image(var->mlx, var->sprites[i++]);
}
