/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:26:09 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:42:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, t_stack **b)
{
	int	tmp;

	if (*a)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
	if (b)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}
	if (a && !b)
		ft_putstr("sa\n");
	else if (!a && b)
		ft_putstr("sb\n");
	else if (a && b)
		ft_putstr("ss\n");
}
