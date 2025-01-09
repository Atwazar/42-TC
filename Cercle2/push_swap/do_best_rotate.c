/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:12:18 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:50:55 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rarb(t_stack **a, t_stack **b, t_infomin *min_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < min_info->pos_a && j < min_info->pos_b)
	{
		rotate(a, b);
		i++;
		j++;
	}
	while (i < min_info->pos_a)
	{
		rotate(a, 0);
		i++;
	}
	while (j < min_info->pos_b)
	{
		rotate(0, b);
		j++;
	}
}

void	do_rarrb(t_stack **a, t_stack **b, t_infomin *min_info)
{
	int	i;
	int	j;
	int	len_b;

	len_b = ft_lst_size(*b);
	i = 0;
	j = 0;
	while (i < min_info->pos_a)
	{
		rotate(a, 0);
		i++;
	}
	while (j < len_b - min_info->pos_b)
	{
		rev_rotate(0, b);
		j++;
	}
}

void	do_rrarb(t_stack **a, t_stack **b, t_infomin *min_info)
{
	int	i;
	int	j;
	int	len_a;

	i = 0;
	j = 0;
	len_a = ft_lst_size(*a);
	while (i < len_a - min_info->pos_a)
	{
		rev_rotate(a, 0);
		i++;
	}
	while (j < min_info->pos_b)
	{
		rotate(0, b);
		j++;
	}
}

void	do_rrarrb(t_stack **a, t_stack **b, t_infomin *min_info)
{
	int	i;
	int	j;
	int	len_a;
	int	len_b;

	i = 0;
	j = 0;
	len_a = ft_lst_size(*a);
	len_b = ft_lst_size(*b);
	while (i < len_a - min_info->pos_a && j < len_b - min_info->pos_b)
	{
		rev_rotate(a, b);
		i++;
		j++;
	}
	while (i < len_a - min_info->pos_a)
	{
		rev_rotate(a, 0);
		i++;
	}
	while (j < len_b - min_info->pos_b)
	{
		rev_rotate(0, b);
		j++;
	}
}

void	do_best_rotate(t_stack **a, t_stack **b, t_infomin *min_info)
{
	if (min_info->mouv == RARB)
		do_rarb(a, b, min_info);
	if (min_info->mouv == RRARB)
		do_rrarb(a, b, min_info);
	if (min_info->mouv == RARRB)
		do_rarrb(a, b, min_info);
	if (min_info->mouv == RRARRB)
		do_rrarrb(a, b, min_info);
	push_a(a, b);
}
