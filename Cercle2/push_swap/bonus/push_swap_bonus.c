/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:01:31 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 16:51:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{	
	int	i;

	i = 0;
	if (!str2)
		return (42);
	while (str1[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	check_command(char *command)
{
	if (!ft_strcmp("ra\n", command))
		return (RA);
	if (!ft_strcmp("rb\n", command))
		return (RB);
	if (!ft_strcmp("rr\n", command))
		return (RR);
	if (!ft_strcmp("rra\n", command))
		return (RRA);
	if (!ft_strcmp("rrb\n", command))
		return (RRB);
	if (!ft_strcmp("rrr\n", command))
		return (RRR);
	if (!ft_strcmp("pa\n", command))
		return (PA);
	if (!ft_strcmp("pb\n", command))
		return (PB);
	if (!ft_strcmp("sa\n", command))
		return (SA);
	if (!ft_strcmp("sb\n", command))
		return (SB);
	if (!ft_strcmp("ss\n", command))
		return (SS);
	return (WRONG_MOUVEMENT);
}

void	do_command(int command_nbr, t_stack **a, t_stack **b)
{
	if (command_nbr == RA)
		rotate_bonus(a, 0);
	else if (command_nbr == RB)
		rotate_bonus(0, b);
	else if (command_nbr == RR)
		rotate_bonus(a, b);
	else if (command_nbr == RRA)
		rev_rotate_bonus(a, 0);
	else if (command_nbr == RRB)
		rev_rotate_bonus(0, b);
	else if (command_nbr == RRR)
		rev_rotate_bonus(a, b);
	else if (command_nbr == PA)
		push_a_bonus(a, b);
	else if (command_nbr == PB)
		push_b_bonus(a, b);
	else if (command_nbr == SA)
		swap_bonus(a, 0);
	else if (command_nbr == SB)
		swap_bonus(0, b);
	else if (command_nbr == SS)
		swap_bonus(a, b);
}

int	follow_the_code(t_stack **a, t_stack **b)
{
	char	*command;
	int		command_nbr;

	command = get_next_line(0, 0);
	while (command)
	{
		command_nbr = check_command(command);
		if (!command_nbr)
		{
			get_next_line(0, 1);
			return (free(command), msg_error(), 0);
		}
		free(command);
		do_command(command_nbr, a, b);
		command = get_next_line(0, 0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	long	*tab;
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (ac == 1)
		return (0);
	tab = create_tablong(ac, av);
	if (!tab)
		return (msg_error(), 0);
	a = create_stack(tab);
	if (!a)
		return (msg_error(), 0);
	if (!follow_the_code(&a, &b))
		return (free_stack(&b), free_stack(&a), 0);
	if (is_sorted(a) && !ft_lst_size(b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (free_stack(&b), free_stack(&a), 0);
}	
