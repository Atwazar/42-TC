/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:23:47 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 12:49:45 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
