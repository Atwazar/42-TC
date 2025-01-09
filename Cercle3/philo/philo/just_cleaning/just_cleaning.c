/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:08:43 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 14:09:06 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	get_size(t_philos *philo)
{
	t_philos	*elem;
	int			len;

	if (!philo)
		return (0);
	elem = philo->next;
	len = 1;
	while (elem != philo)
	{
		elem = elem->next;
		len++;
	}
	return (len);
}

void	free_philos(t_var *var)
{
	t_philos	*current;
	t_philos	*next;
	int			len;

	len = get_size(var->philos);
	current = var->philos;
	while (len--)
	{
		next = current->next;
		if (pthread_mutex_destroy(&current->fork))
			ft_putstr_fd("everything is falling appart\n", 2);
		if (pthread_mutex_destroy(&current->no_modifs))
			ft_putstr_fd("everything is falling appart\n", 2);
		free(current);
		current = next;
	}
}

void	join_threads(t_var *var, int threads_created)
{
	int	i;

	i = 0;
	while (i < threads_created)
		pthread_join(var->philo_threads[i++], 0);
}
