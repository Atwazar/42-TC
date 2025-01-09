/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:15:04 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:49:10 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a, t_stack **b)
{
	if (a)
		*a = (*a)->next;
	if (b)
		*b = (*b)->next;
	if (a && !b)
		ft_putstr("ra\n");
	else if (!a && b)
		ft_putstr("rb\n");
	else if (a && b)
		ft_putstr("rr\n");
}
