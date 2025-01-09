/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:29:20 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 15:29:35 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*fake_routine(void *philo_ptr)
{
	t_philos	*philo;

	philo = (t_philos *)philo_ptr;
	speak(philo, IS_THINKING);
	speak(philo, TAKE_FORK);
	pthread_mutex_lock(philo->can_change);
	while (philo->state == CONTINUE)
	{
		pthread_mutex_unlock(philo->can_change);
		usleep(200);
		pthread_mutex_lock(philo->can_change);
	}
	pthread_mutex_unlock(philo->can_change);
	return (NULL);
}
static void	live_your_life(t_philos *philo)
{
	pthread_mutex_lock(philo->favorite_fork);
	speak(philo, TAKE_FORK);
	pthread_mutex_lock(philo->meh_fork);
	speak(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->no_modifs);
	update_time_last_meal(philo);
	pthread_mutex_unlock(&philo->no_modifs);
	speak(philo, IS_EATING);
	usleep(philo->time_to_eat * CONVERT);
	pthread_mutex_unlock(philo->favorite_fork);
	pthread_mutex_unlock(philo->meh_fork);
	pthread_mutex_lock(&philo->no_modifs);
	philo->nbr_of_meals++;
	pthread_mutex_unlock(&philo->no_modifs);
	speak(philo, IS_SLEEPING);
	usleep(philo->time_to_sleep * CONVERT);
	speak(philo, IS_THINKING);
	if (philo->nbr_of_philos % 2
		&& philo->time_to_sleep < 2 * philo->time_to_eat)
		usleep((philo->time_to_eat) * CONVERT);
}

void	*routine(void *philo_ptr)
{
	t_philos	*philo;

	philo = (t_philos *)philo_ptr;
	speak(philo, IS_THINKING);
	if (!(philo->philo_id % 2))
		usleep((philo->time_to_eat / 2) * CONVERT);
	pthread_mutex_lock(philo->can_change);
	while (*(philo->state) == CONTINUE)
	{
		pthread_mutex_unlock(philo->can_change);
		live_your_life(philo);
		pthread_mutex_lock(philo->can_change);
	}
	pthread_mutex_unlock(philo->can_change);
	return (NULL);
}
