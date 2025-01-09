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

static void	boss_is_speaking(t_philos *philo, t_var *var)
{
	printf("%ld\t%d died\n", var->actual_time, philo->philo_id);
}

static int	check_vitals(t_philos *philo, t_var *var, int *nbr_ate_enough)
{
	if (var->actual_time - philo->time_of_last_meal > var->time_to_die)
	{
		pthread_mutex_lock(&var->speaking_totem);
		pthread_mutex_lock(&var->can_change);
		var->state = END;
		boss_is_speaking(philo, var);
		pthread_mutex_unlock(&var->speaking_totem);
		pthread_mutex_unlock(&var->can_change);
		return (END);
	}
	if (var->max_meal != NO_NEED && (philo->philo_id == 1))
		*nbr_ate_enough = 0;
	if (var->max_meal != NO_NEED && philo->nbr_of_meals >= var->max_meal)
	{
		if (++(*nbr_ate_enough) == var->nbr_of_philo)
		{
			pthread_mutex_lock(&var->speaking_totem);
			pthread_mutex_lock(&var->can_change);
			var->state = END;
			pthread_mutex_unlock(&var->speaking_totem);
			pthread_mutex_unlock(&var->can_change);
			return (END);
		}
	}
	return (CONTINUE);
}

static void	terminate_the_simulation(t_var *var)
{
	join_threads(var, var->nbr_of_philo);
	free_philos(var);
	free(var->philo_threads);
}

void	monitor(t_var *var)
{
	t_philos	*philo_studied;
	int			nbr_ate_enough;

	nbr_ate_enough = 0;
	philo_studied = var->philos;
	while (philo_studied)
	{
		pthread_mutex_lock(&philo_studied->no_modifs);
		var->actual_time = get_time() - var->starting_time;
		if (check_vitals(philo_studied, var, &nbr_ate_enough))
		{
			pthread_mutex_unlock(&philo_studied->no_modifs);
			break ;
		}
		pthread_mutex_unlock(&philo_studied->no_modifs);
		philo_studied = philo_studied->next;
	}
	terminate_the_simulation(var);
}
