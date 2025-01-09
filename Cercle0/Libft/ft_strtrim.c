/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:07:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 16:25:32 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set))
		start++;
	while (is_in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("pauvre con");
		return(0);
	}
	printf("chaine de bose : \"%s\"\n tricaractere : 
	\"%s\"\n chaine trimaxed \"%s\"\n", av[1], av[2], 
	ft_strtrim(av[1],av[2]));
       return(0);
}*/
