/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:45:52 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 13:46:04 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	create_one_lonely_philo_thread(t_var *var)
{
	t_philos	*philo;

	philo = var->philos;
	var->starting_time = get_time();
	if (pthread_create(&var->philo_threads[0], 0, &fake_routine, philo))
	{
		ft_putstr_fd("Error during thread creation", 2);
		return (free(var->philo_threads), free_philos(var), 0);
	}
	return (1);
}

static int	create_multiple_philo_threads(t_var *var)
{
	int			i;
	t_philos	*philo;

	i = 1;
	philo = var->philos;
		var->starting_time = get_time();
	while (i < var->nbr_of_philo + 1)
	{
		if (pthread_create(&var->philo_threads[i - 1], 0, &routine, philo))
		{
			ft_putstr_fd("Error during thread creation", 2);
			var->state = END;
			join_threads(var, i - 1);
			return (free(var->philo_threads), free_philos(var), 0);
		}
		i++;
		philo = philo->next;
	}
	return (1);
}

static void	malloc_error(void)
{
	ft_putstr_fd("error of memory allocation\n", 2);
}

int	create_philo_thread(t_var *var)
{
	var->philo_threads = malloc(sizeof(pthread_t) * var->nbr_of_philo);
	if (!var->philo_threads)
		return (malloc_error(), free_philos(var), 0);
	if (var->nbr_of_philo == 1)
		return (create_one_lonely_philo_thread(var));
	else
		return (create_multiple_philo_threads(var));
}
