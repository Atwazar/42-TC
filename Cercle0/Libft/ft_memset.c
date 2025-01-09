/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:49 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 12:43:03 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t n)
{
	size_t	i;
	char	*char_ptr;

	i = 0;
	char_ptr = (char *)ptr;
	while (i < n)
	{
		char_ptr[i] = val;
		i++;
	}
	return (ptr);
}
