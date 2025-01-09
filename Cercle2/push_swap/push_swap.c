/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:01:31 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/11 19:58:48 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*tab;
	t_stack	*a;

	a = 0;
	if (ac == 1)
		return (0);
	tab = create_tablong(ac, av);
	if (!tab)
		return (msg_error(), 0);
	if (tab[0] == 1)
		return (free(tab), 0);
	a = create_stack(tab);
	if (!a)
		return (msg_error(), 0);
	sort(a, tab);
	return (free_stack(&a), free(tab), 0);
}	
