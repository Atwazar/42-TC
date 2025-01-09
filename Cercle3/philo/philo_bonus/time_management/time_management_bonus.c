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

void	init_time(t_var *var)
{
	struct timeval	starting_time_struct;

	var->starting_time = 0;
	gettimeofday(&starting_time_struct, 0);
	var->starting_time += starting_time_struct.tv_sec * 1000;
	var->starting_time += starting_time_struct.tv_usec / 1000;
}

long	get_time(t_var *philo)
{
	struct timeval	actual_time;
	long			time;

	gettimeofday(&actual_time, 0);
	time = actual_time.tv_sec * 1000;
	time += actual_time.tv_usec / 1000;
	time -= philo->starting_time;
	return (time);
}

void	get_actual_time(t_var *philo)
{
	struct timeval	actual_time_struct;

	gettimeofday(&actual_time_struct, 0);
	philo->time = actual_time_struct.tv_sec * 1000;
	philo->time += actual_time_struct.tv_usec / 1000;
	philo->time -= philo->starting_time;
}

void	update_time_last_meal(t_var *philo)
	{
	struct timeval	actual_time_struct;

	gettimeofday(&actual_time_struct, 0);
	philo->time_of_last_meal = actual_time_struct.tv_sec * 1000;
	philo->time_of_last_meal += actual_time_struct.tv_usec / 1000;
	philo->time_of_last_meal -= philo->starting_time;
}
