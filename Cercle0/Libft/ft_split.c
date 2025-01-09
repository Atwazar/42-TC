/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:30:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/07 18:55:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strreallen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_split(char **splitted)
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

char	**ft_split(char const *s, char c)
{
	int		ij[2];
	int		count;
	char	**splitted;

	ij[0] = 0;
	ij[1] = 0;
	count = count_words(s, c);
	splitted = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!splitted)
		return (0);
	while (ij[0] < count)
	{
		while (s[ij[1]] && s[ij[1]] == c)
			ij[1]++;
		splitted[ij[0]] = ft_substr(s, ij[1], ft_strreallen(&s[ij[1]], c));
		if (!splitted[ij[0]])
		{
			free_split(splitted);
			return (0);
		}
		ij[1] += ft_strreallen(&s[ij[1]], c);
		ij[0]++;
	}
	splitted[ij[0]] = 0;
	return (splitted);
}
/*
int	main(void)
{
	int	i = 0;
	char **result = ft_split("hello", ' ');
	while (i < 1)
	{
		printf("%s\n",result[i]);
		i++;
	}
	printf("c ok");
	return(0);
}*/
