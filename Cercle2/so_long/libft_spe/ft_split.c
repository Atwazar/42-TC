/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:30:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/02 16:46:58 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"

static int	ft_strreallen(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words(char *s, char c, t_var *var)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
			if (s[i] == c)
				dimension_error(var);
		}
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (!count)
		no_map_error(var);
	return (count);
}

char	**ft_split(char *s, char c, t_var *var)
{
	int		i;
	int		j;
	int		count;
	char	**splitted;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	count = count_words(s, c, var);
	splitted = (char **)ft_calloc(count + 1, sizeof(char *), var);
	while (i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		splitted[i] = ft_substr(s, j, ft_strreallen(&s[j], c), var);
		j += ft_strreallen(&s[j], c);
		i++;
	}
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
