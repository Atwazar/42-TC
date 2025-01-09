/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:55:52 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 13:56:12 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	mutex_error(void)
{
	ft_putstr_fd("Error during mutex creation\n", 2);
}

static int	add_new_philo(t_var *var, t_philos *new_philo, int i)
{
	new_philo->philo_id = i;
	if (pthread_mutex_init(&new_philo->fork, 0))
		return (mutex_error(), free(new_philo), free_philos(var), 0);
	if (pthread_mutex_init(&new_philo->no_modifs, 0))
	{
		pthread_mutex_destroy(&new_philo->fork);
		return (mutex_error(), free(new_philo), free_philos(var), 0);
	}
	if (!var->philos)
	{
		var->philos = new_philo;
		new_philo->next = new_philo;
		new_philo->prev = new_philo;
	}
	else
	{
		new_philo->next = var->philos;
		new_philo->prev = var->philos->prev;
		new_philo->next->prev = new_philo;
		new_philo->prev->next = new_philo;
	}
	return (1);
}

static void	init_philo_2(t_philos *philo, t_var *var)
{
	philo->time_to_die = var->time_to_die;
	philo->time_to_eat = var->time_to_eat;
	philo->time_to_sleep = var->time_to_sleep;
	philo->state = &var->state;
	philo->starting_time = &var->starting_time;
	philo->nbr_of_meals = 0;
	philo->speaking_totem = &var->speaking_totem;
	philo->time_of_last_meal = 0;
	philo->can_change = &var->can_change;
	philo->nbr_of_philos = var->nbr_of_philo;
}

static void	init_philo(t_var *var)
{
	int			i;
	t_philos	*philo;

	philo = var->philos;
	i = 1;
	while (i < var->nbr_of_philo + 1)
	{
		if (i % 2)
		{
			philo->favorite_fork = &philo->fork;
			philo->meh_fork = &philo->prev->fork;
		}
		else
		{
			philo->favorite_fork = &philo->prev->fork;
			philo->meh_fork = &philo->fork;
		}
		init_philo_2(philo, var);
		philo = philo->next;
		i++;
	}
}

int	create_philo_table(t_var *var)
{
	int			i;
	t_philos	*new_philo;

	i = 0;
	while (i++ < var->nbr_of_philo)
	{
		new_philo = malloc(sizeof(t_philos));
		if (!new_philo)
			return (ft_putstr_fd("memory error\n", 2), free_philos(var), 0);
		if (!add_new_philo(var, new_philo, i))
			return (0);
	}
	if (pthread_mutex_init(&var->speaking_totem, 0))
		return (mutex_error(), free_philos(var), 0);
	if (pthread_mutex_init(&var->can_change, 0))
	{
		pthread_mutex_destroy(&var->speaking_totem);
		return (mutex_error(), free_philos(var), 0);
	}
	return (init_philo(var), 1);
}
