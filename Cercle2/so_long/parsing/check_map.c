/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:40 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:47:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_only_ones(char *line, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->len_ref)
	{
		if (line[i] != '1')
			border_error(var);
		i++;
	}
}

static void	check_line_component(char *line, int line_nbr, t_var *var)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != 'M')
			char_error(line[i], var);
		else if (line[i] == 'P')
		{
			var->row = line_nbr;
			var->col = i;
			var->player++;
		}
		else if (line[i] == 'E')
		{
			var->row_exit = line_nbr;
			var->col_exit = i;
			var->exit++;
		}
		else if (line[i] == 'C')
			var->coins++;
		i++;
	}
}

static void	check_map_component(t_var *var)
{
	int		i;
	char	**map;

	map = var->map;
	i = 0;
	check_only_ones(map[i], var);
	i++;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][var->len_ref - 1] != '1')
			border_error(var);
		check_line_component(map[i], i, var);
		i++;
	}
	check_only_ones(map[i - 1], var);
	if (var->player != 1 || var->exit != 1 || var->coins < 1)
		map_config_error(var);
}

static void	check_dimension(t_var *var)
{
	int		i;
	char	**map;

	map = var->map;
	i = 0;
	var->len_ref = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != var->len_ref)
			dimension_error(var);
		i++;
	}
	var->height = i;
}

void	check_map(t_var *var)
{
	var->player = 0;
	var->exit = 0;
	var->coins = 0;
	var->map = ft_split(var->map_unsplit, '\n', var);
	check_dimension(var);
	check_map_component(var);
}
