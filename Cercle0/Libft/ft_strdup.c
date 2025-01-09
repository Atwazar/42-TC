/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:31:15 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/22 10:41:35 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		i;
	char	*dest;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
