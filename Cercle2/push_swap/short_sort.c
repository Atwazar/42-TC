/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:03:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:49:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->content > ((*a)->next)->content)
		rotate(a, 0);
}

void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->content;
	y = ((*a)->next)->content;
	z = ((*a)->previous)->content;
	if (x < y && x < z && y > z)
	{
		swap(a, 0);
		rotate(a, 0);
	}
	else if (x > y && x < z && y < z)
		swap(a, 0);
	else if (x < y && x > z && y > z)
		rev_rotate(a, 0);
	else if (x > y && x > z && y < z)
		rotate(a, 0);
	else if (x > y && x > z && y > z)
	{
		swap(a, 0);
		rev_rotate(a, 0);
	}
}
