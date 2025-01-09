/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:23 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 12:51:49 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(tofind) == 0)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == tofind[j] && i + j < n)
		{
			if (!tofind[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
