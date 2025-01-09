/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:16:41 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/13 21:34:14 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	msg_error(void)
{
	write(2, "Error\n", 6);
}

int	is_sorted(t_stack *a)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lst_size(a);
	if (len == 0)
		return (0);
	while (--len)
	{
		if (a->content > (a->next)->content)
			return (0);
		a = a->next;
	}
	return (1);
}
