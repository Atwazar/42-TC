/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 09:54:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 15:10:31 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!join)
		return (0);
	ft_strlcat(join, s1, len_s1 + len_s2 + 1);
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	return (join);
}
