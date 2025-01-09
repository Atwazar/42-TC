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

#include "../push_swap.h"

void	swap_bonus(t_stack **a, t_stack **b)
{
	int	tmp;

	if (a && *a)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
	if (b && *b)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}
}
