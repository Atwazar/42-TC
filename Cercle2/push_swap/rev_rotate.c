/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:15:04 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:48:53 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **a, t_stack **b)
{
	if (a)
		*a = (*a)->previous;
	if (b)
		*b = (*b)->previous;
	if (a && !b)
		ft_putstr("rra\n");
	else if (!a && b)
		ft_putstr("rrb\n");
	else if (a && b)
		ft_putstr("rrr\n");
}
