/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:06:48 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/12 19:17:27 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_empty(t_stack **src, t_stack **dest)
{
	*dest = *src;
	((*src)->next)->previous = (*src)->previous;
	((*src)->previous)->next = (*src)->next;
	*src = (*src)->next;
	(*dest)->previous = *dest;
	(*dest)->next = *dest;
}

void	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	if (ft_lst_size(*src) != 1)
	{
		((*src)->next)->previous = (*src)->previous;
		((*src)->previous)->next = (*src)->next;
		*src = (*src)->next;
	}
	else
		*src = 0;
	tmp->next = *dest;
	((*dest)->previous)->next = tmp;
	tmp->previous = (*dest)->previous;
	(*dest)->previous = tmp;
	*dest = (*dest)->previous;
}

void	push_b_bonus(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	if (*b == NULL)
		push_empty(a, b);
	else
		push_stack(a, b);
}

void	push_a_bonus(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	if (*a == NULL)
		push_empty(b, a);
	else
		push_stack(b, a);
}
