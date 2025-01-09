/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:48:36 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:44:07 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_short(t_stack **a, t_stack **b)
{
	while (ft_lst_size(*a) > 3)
		push_b(a, b);
}

void	pre_sort_big(t_stack **a, t_stack **b, long *tab)
{
	int	q1;
	int	q2;
	int	q3;

	q1 = find_quart(tab, 1);
	q2 = find_quart(tab, 2);
	q3 = find_quart(tab, 3);
	while (ft_lst_size(*a) > 3 && highvalue_remains(*a, q2))
	{
		if ((*a)->content < q2)
			push_b(a, b);
		if (ft_lst_size(*b) > 1 && (*b)->content < q1
			&& !((*a)->content < q2))
			rotate(a, b);
		else if (ft_lst_size(*b) > 1 && (*b)->content < q1)
			rotate(0, b);
		else
			rotate(a, 0);
	}
	while (ft_lst_size(*a) > 3)
	{
		push_b(a, b);
		if ((*b)->content > q3)
			rotate(0, b);
	}
}

void	pre_sort(t_stack **a, t_stack **b, long *tab)
{
	int	len_a;

	len_a = ft_lst_size(*a);
	if (len_a == 2)
		sort_2(a);
	else if (len_a < 10)
		pre_sort_short(a, b);
	else
	{
		tab = sort_tab(tab);
		pre_sort_big(a, b, tab);
	}
	sort_3(a);
}
