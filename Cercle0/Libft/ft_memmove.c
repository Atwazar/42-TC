/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:49 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 12:47:10 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dest;
	char		*char_src;

	if (!dest && !src)
		return (0);
	i = 0;
	char_dest = (char *)dest;
	char_src = (char *)src;
	if (dest <= src)
	{
		while (i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	while (i < n)
	{
		char_dest[n - 1 - i] = char_src[n - 1 - i];
		i++;
	}
	return (dest);
}
