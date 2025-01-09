/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:27:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/14 17:32:19 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	add_stack(t_stack **first_elem, int content)
{
	t_stack	*new_elem;
	t_stack	*last_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	if (!new_elem)
		return (0);
	last_elem = (*first_elem)->previous;
	new_elem->content = content;
	new_elem->next = *first_elem;
	last_elem->next = new_elem;
	new_elem->previous = (*first_elem)->previous;
	(*first_elem)->previous = new_elem;
	return (1);
}

t_stack	*create_stack(long *tab)
{
	int		i;
	t_stack	*a;
	int		check;

	a = 0;
	i = 1;
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (0);
	a->content = tab[i];
	a->next = a;
	a->previous = a;
	while (i < tab[0])
	{
		check = add_stack(&a, (int)tab[i + 1]);
		if (!check)
			return (free_stack(&a), free(tab), NULL);
		i++;
	}
	free(tab);
	return (a);
}
