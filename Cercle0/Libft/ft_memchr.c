/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:48:27 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 13:29:07 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int val, size_t n)
{
	size_t			i;
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *) ptr;
	i = 0;
	while (i < n)
	{
		if (char_ptr[i] == (unsigned char)val)
			return (&char_ptr[i]);
		i++;
	}
	return (0);
}
