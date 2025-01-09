/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:38:44 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/29 17:40:52 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time(void)
{
	struct timeval	actual_time;
	long			time;

	gettimeofday(&actual_time, 0);
	time = actual_time.tv_sec * CONVERT;
	time += actual_time.tv_usec / CONVERT;
	return (time);
}

void	update_time_last_meal(t_philos *philo)
{
	long	actual_time;

	actual_time = get_time();
	philo->time_of_last_meal = actual_time - *(philo->starting_time);
}
