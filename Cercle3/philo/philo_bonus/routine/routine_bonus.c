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

void	fake_routine(t_var *philo)
{
	speak(philo, IS_THINKING);
	speak(philo, TAKE_FORK);
	usleep(philo->time_to_die * CONVERT);
	get_actual_time(philo);
	printf("%ld\t%d died\n", philo->time, philo->philo_id);
	sem_post(philo->state);
	exit(1);
}

static void	*life_monitoring(void *philo_ptr)
{
	t_var	*philo;
	long	time;

	philo = (t_var *)philo_ptr;
	time = 0;
	while (1)
	{
		sem_wait(philo->dont_change);
		time = get_time(philo);
		if (time - philo->time_of_last_meal > philo->time_to_die)
		{
			sem_wait(philo->speaking_totem);
			printf("%ld\t%d died\n", time, philo->philo_id);
			sem_post(philo->state);
			exit(1);
		}
		sem_post(philo->dont_change);
		usleep(100);
	}
}

static void	create_thread(t_var *philo)
{
	char	str[4];

	str[0] = philo->philo_id / 100 + 48;
	str[1] = (philo->philo_id - (philo->philo_id / 100 * 100)) / 10 + 48;
	str[2] = philo->philo_id - (philo->philo_id / 10 * 10) + 48;
	str[3] = '\0';
	sem_unlink(str);
	philo->dont_change = sem_open(str, O_CREAT | O_EXCL, 0666, 1);
	if (!philo->dont_change)
	{
		sem_wait(philo->speaking_totem);
		ft_putstr_fd("Error during semaphore creation\n", 2);
		sem_post(philo->state);
		exit(1);
	}
	if (pthread_create(&philo->life_monitor, 0, &life_monitoring, philo))
	{
		ft_putstr_fd("Error during thread creation", 2);
		sem_wait(philo->speaking_totem);
		sem_post(philo->state);
		exit(1);
	}
}

static void	routine_loop(t_var *philo)
{
	sem_wait(philo->forks_owners);
	sem_wait(philo->forks);
	speak(philo, TAKE_FORK);
	sem_wait(philo->forks);
	speak(philo, TAKE_FORK);
	sem_wait(philo->dont_change);
	update_time_last_meal(philo);
	sem_post(philo->dont_change);
	speak(philo, IS_EATING);
	usleep(philo->time_to_eat * CONVERT);
	sem_post(philo->forks_owners);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (philo->max_meal != NO_NEED
		&& ++philo->nbr_of_meal == philo->max_meal)
		sem_post(philo->ate_enough);
	speak(philo, IS_SLEEPING);
	usleep(philo->time_to_sleep * CONVERT);
	speak(philo, IS_THINKING);
	if (philo->nbr_of_philo % 2)
		usleep(philo->time_to_eat * CONVERT / 2);
}

void	routine(t_var *philo)
{
	speak(philo, IS_THINKING);
	create_thread(philo);
	sem_wait(philo->dont_change);
	update_time_last_meal(philo);
	sem_post(philo->dont_change);
	while (1)
		routine_loop(philo);
}
