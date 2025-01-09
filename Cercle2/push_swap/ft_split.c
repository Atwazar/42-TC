/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:30:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:19:19 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strreallen(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != 32)
		len++;
	return (len);
}

int	count_words(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == 32)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != 32)
			i++;
	}
	return (count);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free (splitted[i]);
		i++;
	}
	free(splitted);
}

char	**ft_split(char *s, int count)
{
	int		ij[2];
	char	**splitted;

	ij[0] = 0;
	ij[1] = 0;
	splitted = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splitted)
		return (0);
	while (ij[0] < count)
	{
		while (s[ij[1]] && s[ij[1]] == 32)
			ij[1]++;
		splitted[ij[0]] = ft_substr(s, ij[1], ft_strreallen(&s[ij[1]]));
		if (!splitted[ij[0]])
		{
			free_split(splitted);
			return (0);
		}
		ij[1] += ft_strreallen(&s[ij[1]]);
		ij[0]++;
	}
	return (splitted);
}
/*
int	main(int ac, char **av)
{
	int	i = 0;
	if (ac != 2)
		return (0);
	int	count = count_words(av[1]);
	char **result = ft_split(av[1], count);
	while (i < count)
	{
		printf("%s\n",result[i]);
		i++;
	}
	printf("split ok\n");
	int	*tab = create_tab(result, count);
	i = 0;
	while (i < count + 1)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return(0);

}*/
