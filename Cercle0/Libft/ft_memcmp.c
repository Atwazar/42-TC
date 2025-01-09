/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:48:27 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 13:49:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*char_ptr1;
	unsigned char	*char_ptr2;

	i = 0;
	char_ptr1 = (unsigned char *)ptr1;
	char_ptr2 = (unsigned char *)ptr2;
	while (i < n && char_ptr1[i] == char_ptr2[i])
	{
		i++;
	}
	if (i < n)
		return ((unsigned char)char_ptr1[i] - (unsigned char)char_ptr2[i]);
	return (0);
}
