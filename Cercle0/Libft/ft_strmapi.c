/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:51:01 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 18:15:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	i = 0;
	strmapi = ft_strdup(s);
	if (!strmapi)
		return (0);
	while (strmapi[i])
	{
		strmapi[i] = f(i, strmapi[i]);
		i++;
	}
	return (strmapi);
}
