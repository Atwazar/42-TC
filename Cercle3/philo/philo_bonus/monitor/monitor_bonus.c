/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:18:55 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/31 12:19:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	make_sure_hes_dead(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->nbr_of_philo)
	{
		sem_post(var->ate_enough);
		i++;
	}
	pthread_join(var->life_monitor, 0);
}

static void	*monitor(void *var_ptr)
{
	t_var	*var;
	int		nbr_ate_enough;

	nbr_ate_enough = 0;
	var = (t_var *)var_ptr;
	while (nbr_ate_enough < var->nbr_of_philo)
	{
		sem_wait(var->ate_enough);
		nbr_ate_enough++;
	}
	sem_wait(var->speaking_totem);
	sem_post(var->state);
	return (NULL);
}

int	create_monitor(t_var *var)
{
	if (pthread_create(&var->life_monitor, 0, &monitor, var))
	{
		ft_putstr_fd("Error during thread creation", 2);
		return (0);
	}
	return (1);
}
