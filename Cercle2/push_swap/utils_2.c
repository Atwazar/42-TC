/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:15:52 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:20:35 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlcpy(char *dest, char *src, size_t n)
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

char	*ft_substr(char *str, int start, size_t len)
{
	size_t	len_dest;
	char	*substr;

	if (start >= ft_strlen(str))
		len_dest = 0;
	else
		len_dest = ft_strlen(str + start);
	if (len_dest > len)
		len_dest = len;
	substr = ft_calloc(len_dest + 1, sizeof(char));
	if (!substr)
		return (0);
	if (len_dest == 0)
		ft_strlcpy(substr, str, len_dest + 1);
	else
		ft_strlcpy(substr, str + start, len_dest + 1);
	return (substr);
}

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void	*tab;
	size_t	i;

	if (size_elem != 0 && nb_elem > ((size_t) -1 / size_elem))
		return (0);
	i = 0;
	tab = (void *)malloc(nb_elem * size_elem);
	if (!tab)
		return (0);
	while (i < nb_elem * size_elem)
	{
		*(unsigned char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}

int	ft_lst_size(t_stack *a)
{
	int		len;
	t_stack	*elem;

	if (!a)
		return (0);
	len = 1;
	elem = a->next;
	while (elem != a)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}
