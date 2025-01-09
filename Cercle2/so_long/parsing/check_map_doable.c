/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_doable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:47:12 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/19 16:47:35 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

static int	is_doable(int mouvement, t_player_info *player_info)
{
	if (mouvement == GO_UP)
	{
		if (dont_pars(player_info->map, player_info->row - 1, player_info->col))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_DOWN)
	{
		if (dont_pars(player_info->map, player_info->row + 1, player_info->col))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_LEFT)
	{
		if (dont_pars(player_info->map, player_info->row, player_info->col - 1))
			return (IS_DOABLE);
	}
	else if (mouvement == GO_RIGHT)
	{
		if (dont_pars(player_info->map, player_info->row, player_info->col + 1))
			return (IS_DOABLE);
	}
	return (IS_NOT_DOABLE);
}

static void	do_it_then(int mouvement, t_player_info *player_info)
{
	if (mouvement == GO_UP)
		player_info->row--;
	else if (mouvement == GO_DOWN)
		player_info->row++;
	else if (mouvement == GO_LEFT)
		player_info->col--;
	else if (mouvement == GO_RIGHT)
		player_info->col++;
	if ((player_info->map)[player_info->row][player_info->col] == 'C')
		player_info->coins_left--;
	if ((player_info->map)[player_info->row][player_info->col] == 'E')
		player_info->exit_left--;
	(player_info->map)[player_info->row][player_info->col] = 'P';
}

static void	undo_move(int mouvement, t_player_info *player_info)
{
	if (mouvement == GO_UP)
		player_info->row++;
	else if (mouvement == GO_DOWN)
		player_info->row--;
	else if (mouvement == GO_LEFT)
		player_info->col++;
	else if (mouvement == GO_RIGHT)
		player_info->col--;
}

static int	backtrack_map(t_player_info *player_info)
{
	int	mouvement;

	if (!player_info->coins_left && !player_info->exit_left)
		return (1);
	mouvement = 0;
	while (mouvement < NUMBER_OF_MOUV)
	{
		if (is_doable(mouvement, player_info))
		{
			do_it_then(mouvement, player_info);
			if (backtrack_map(player_info))
				return (1);
			undo_move(mouvement, player_info);
		}
		mouvement++;
	}
	return (0);
}

void	check_map_doable(t_var *var)
{
	t_player_info	player_info;

	player_info.row = var->row;
	player_info.col = var->col;
	player_info.exit_left = var->exit;
	player_info.coins_left = var->coins;
	player_info.map = ft_split(var->map_unsplit, '\n', var);
	ft_free(var->map_unsplit, var);
	if (!backtrack_map(&player_info))
		map_not_doable_error(var);
	ft_free(player_info.map, var);
}
