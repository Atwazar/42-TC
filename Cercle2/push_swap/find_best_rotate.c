/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:45:32 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:55:38 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_min(t_infomin **min_i)
{
	(*min_i)->pos_a = 0;
	(*min_i)->pos_b = 0;
	(*min_i)->len_a = 0;
	(*min_i)->len_b = 0;
	(*min_i)->nbr_mouv = 0;
	(*min_i)->mouv = 0;
}

t_infomin	*calculate_rotate(t_infomin *min_i, int pos_a, int pos_b)
{
	int	rarb;
	int	rarrb;
	int	rrarb;
	int	rrarrb;
	int	min;

	rarb = ft_max(pos_a, pos_b);
	rarrb = pos_a + min_i->len_b - pos_b;
	rrarb = min_i->len_a - pos_a + pos_b;
	rrarrb = ft_max(min_i->len_a - pos_a, min_i->len_b - pos_b);
	min = ft_min(rarb, ft_min(rarrb, ft_min(rrarb, rrarrb)));
	if (!(min < min_i->nbr_mouv))
		return (min_i);
	min_i->nbr_mouv = min;
	min_i->pos_a = pos_a;
	min_i->pos_b = pos_b;
	if (min == rarb)
		min_i->mouv = RARB;
	else if (min == rarrb)
		min_i->mouv = RARRB;
	else if (min == rrarb)
		min_i->mouv = RRARB;
	else if (min == rrarrb)
		min_i->mouv = RRARRB;
	return (min_i);
}

t_infomin	*find_best_rotate(t_stack *a, t_stack *b)
{
	t_infomin	*min_info;
	int			i;
	int			pos_a;
	int			pos_b;

	i = 0;
	min_info = malloc(sizeof(t_infomin));
	if (!min_info)
		return (0);
	clean_min(&min_info);
	min_info->len_a = ft_lst_size(a);
	min_info->len_b = ft_lst_size(b);
	min_info->nbr_mouv = min_info->len_a * min_info->len_a;
	while (i < min_info->len_b)
	{
		pos_b = i;
		pos_a = find_elem_place(b->content, a);
		min_info = calculate_rotate(min_info, pos_a, pos_b);
		if (min_info->nbr_mouv == 0)
			break ;
		i++;
		b = b->next;
	}
	return (min_info);
}
