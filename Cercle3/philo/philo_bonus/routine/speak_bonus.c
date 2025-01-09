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

static void	print_message(int philo_id, int action, long time)
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

void	speak(t_var *philo, int action)
{
	sem_wait(philo->speaking_totem);
	get_actual_time(philo);
	print_message(philo->philo_id, action, philo->time);
	sem_post(philo->speaking_totem);
}
