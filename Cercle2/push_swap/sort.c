/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:02:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:57:21 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lst_size(a);
	while (len)
	{
		if (a->content > (a->next)->content)
			i++;
		a = a->next;
		len--;
	}
	return (i);
}

void	sort(t_stack *a, long *tab)
{
	t_stack		*b;
	t_infomin	*min_info;
	int			check_sorted;

	b = 0;
	b = 0;
	check_sorted = is_sorted(a);
	if (check_sorted == 1 || check_sorted == 0)
		return (go_to_first_elem(&a));
	pre_sort(&a, &b, tab);
	while (ft_lst_size(b))
	{
		min_info = find_best_rotate(a, b);
		do_best_rotate(&a, &b, min_info);
		free(min_info);
	}
	go_to_first_elem(&a);
}	
