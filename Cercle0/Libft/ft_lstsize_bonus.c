/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:55:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 10:53:13 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*elem;

	if (!lst)
		return (0);
	elem = lst;
	i = 1;
	while (elem->next)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
