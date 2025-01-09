/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:16:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/12 19:30:31 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	free_stack(t_stack **a)
{
	t_stack	*save;
	int		len;
	int		i;

	i = 0;
	len = ft_lst_size(*a);
	while (i < len)
	{
		save = (*a)->next;
		free(*a);
		(*a) = save;
		i++;
	}
}

int	highvalue_remains(t_stack *a, int q2)
{
	t_stack	*elem;

	if (!a)
		return (0);
	if (a->content < q2)
		return (1);
	elem = a->next;
	while (elem != a)
	{
		if (elem->content < q2)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void	msg_error(void)
{
	write(2, "Error\n", 6);
}
