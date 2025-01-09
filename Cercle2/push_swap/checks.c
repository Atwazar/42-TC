/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:46:17 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/06 14:40:02 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (!(c < '0' || c > '9'));
}

int	check_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && i && (str[i] != '-' || str[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

int	check_split(char **splitted, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!check_str(splitted[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_tab(long	*tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab[0])
	{
		if (tab[i + 1] > INT_MAX || tab[i + 1] < INT_MIN)
			return (0);
		j = i + 1;
		while (j < tab[0])
		{
			if (tab[i + 1] == tab[j + 1])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
