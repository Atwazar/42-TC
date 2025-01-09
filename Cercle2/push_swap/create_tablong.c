/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tablong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:11:13 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 20:24:45 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	int		sign;
	long	n;

	n = 0;
	sign = 1;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (!(*str < '0' || *str > '9'))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}

long	*free_create_tab(char **splitted, int ac)
{
	if (ac == 2)
		free_split(splitted);
	return (0);
}

long	*create_tab(char **splitted, int len, int ac)
{
	long	*tab;
	int		i;

	i = 0;
	tab = malloc((len + 2) * sizeof(long));
	if (!tab)
	{
		if (ac == 2)
			free_split(splitted);
		return (0);
	}
	tab[0] = len;
	while (i < len)
	{
		if (ft_strlen(splitted[i]) > 12 || !ft_strlen(splitted[i]))
			return (free (tab), free_create_tab(splitted, ac));
		tab[i + 1] = ft_atoi(splitted[i]);
		i++;
	}
	if (ac == 2)
		free_split(splitted);
	return (tab);
}

long	*create_and_check(char **splitted, int count, int ac)
{
	long	*tab;

	tab = create_tab(splitted, count, ac);
	if (!tab)
		return (0);
	if (!check_tab(tab))
		return (free(tab), NULL);
	return (tab);
}

long	*create_tablong(int ac, char **av)
{
	long	*tab;
	char	**splitted;
	int		count;

	if (ac == 2)
	{
		count = count_words(av[1]);
		splitted = ft_split(av[1], count);
		if (!splitted)
			return (0);
	}
	else
	{
		splitted = &av[1];
		count = ac - 1;
	}
	if (!check_split(splitted, count))
	{
		if (ac == 2)
			free_split(splitted);
		return (0);
	}
	tab = create_and_check(splitted, count, ac);
	return (tab);
}
