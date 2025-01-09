/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:01:56 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 18:02:12 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_message(int philo_id, t_action action, long time)
{
	if (action == TAKE_FORK)
		printf("%ld\t%d has taken a fork\n", time, philo_id);
	if (action == IS_EATING)
		printf("%ld\t%d is eating\n", time, philo_id);
	if (action == IS_SLEEPING)
		printf("%ld\t%d is sleeping\n", time, philo_id);
	if (action == IS_THINKING)
		printf("%ld\t%d is thinking\n", time, philo_id);
}

void	speak(t_philos *philo, t_action action)
{
	pthread_mutex_lock(philo->speaking_totem);
	philo->actual_time = get_time() - *philo->starting_time;
	pthread_mutex_lock(philo->can_change);
	if (*(philo->state) == CONTINUE)
	{
		pthread_mutex_unlock(philo->can_change);
		print_message(philo->philo_id, action, philo->actual_time);
	}
	else
		pthread_mutex_unlock(philo->can_change);
	pthread_mutex_unlock(philo->speaking_totem);
}
