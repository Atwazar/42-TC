/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quartile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:49:09 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:50:12 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*sort_tab(long *tab)
{
	long	i;
	long	j;
	long	tmp;

	i = 0;
	while (i < tab[0])
	{
		j = 0;
		while (j < tab[0] - i - 1)
		{
			if (tab[j + 1] > tab[j + 2])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j + 2];
				tab[j + 2] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	find_quart(long *tab, int quart_number)
{
	return ((int)tab[tab[0] / 4 * quart_number]);
}
