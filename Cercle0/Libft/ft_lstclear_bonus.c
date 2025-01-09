/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:52:04 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 12:00:15 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem1;
	t_list	*elem2;

	if (!lst || !del)
		return ;
	elem1 = *lst;
	while (elem1)
	{
		elem2 = elem1->next;
		ft_lstdelone(elem1, del);
		elem1 = elem2;
	}
	*lst = 0;
}
