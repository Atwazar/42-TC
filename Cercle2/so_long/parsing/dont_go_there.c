/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_go_there.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:09:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/27 20:26:29 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

int	dont_pars(char **map, int row, int col)
{
	return (map[row][col] != '1' && map[row][col] != 'P'
		&& map[row][col] != 'M');
}

int	dont_go(char **map, int row, int col)
{
	return (map[row][col] != '1' && map[row][col] != 'P');
}
