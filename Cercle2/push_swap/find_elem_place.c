/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:28:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:46:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_first_elem(t_stack **a)
{
	int		i;
	int		len;
	t_stack	*elem;

	i = 0;
	len = ft_lst_size(*a);
	elem = *a;
	while (i < len && elem->content > (elem->previous)->content)
	{
		i++;
		elem = elem->next;
	}
	if (i < len / 2)
	{
		while (i--)
			rotate(a, 0);
	}
	else
	{
		i = len - i;
		while (i--)
			rev_rotate(a, 0);
	}
}

int	find_elem_place(int content, t_stack *stack)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lst_size(stack);
	while (i < len)
	{
		if (content < stack->content
			&& content > (stack->previous)->content)
			return (i);
		i++;
		stack = stack->next;
	}
	i = 0;
	while (i < len)
	{
		if (stack->content < (stack->previous)->content)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}
