/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:55:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/23 11:41:28 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*elem;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	elem = 0;
	first_elem = 0;
	while (lst)
	{
		tmp = f(lst->content);
		elem = ft_lstnew(tmp);
		if (!elem)
		{
			del(tmp);
			ft_lstclear(&first_elem, del);
			return (0);
		}
		ft_lstadd_back(&first_elem, elem);
		lst = lst->next;
	}
	return (first_elem);
}
