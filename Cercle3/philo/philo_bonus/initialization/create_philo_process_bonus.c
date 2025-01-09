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

static void	fork_error(void)
{
	ft_putstr_fd("error during fork creation\n", 2);
}

static void	create_one_lonely_philo_process(t_var *var)
{
	init_time(var);
	var->philo_id = LONELY_PHILO + 1;
	var->pids[LONELY_PHILO] = fork();
	if (var->pids[LONELY_PHILO] == -1)
		return (sem_post(var->state), fork_error());
	if (var->pids[LONELY_PHILO] == 0)
		fake_routine(var);
}

static void	create_multiple_philo_process(t_var *var)
{
	int	i;

	i = 0;
	init_time(var);
	while (i < var->nbr_of_philo)
	{
		var->philo_id = i + 1;
		var->pids[i] = fork();
		if (var->pids[i] == -1)
			return (sem_post(var->state), fork_error());
		if (var->pids[i] == 0)
			routine(var);
		i++;
	}
}

static void	create_philo_process(t_var *var)
{
	int	i;

	i = 0;
	var->pids = malloc(var->nbr_of_philo * sizeof(pid_t));
	if (!var->pids)
	{
		ft_putstr_fd("error of memory allocation\n", 2);
		return (close_semaphore(var, 5));
	}
	if (var->nbr_of_philo == 1)
		return (create_one_lonely_philo_process(var));
	else
		return (create_multiple_philo_process(var));
}

int	do_the_simulation(t_var *var)
{
	int	i;

	if (var->max_meal != NO_NEED && !create_monitor(var))
		return (close_semaphore(var, 5), 0);
	create_philo_process(var);
	sem_wait(var->state);
	i = 0;
	while (i < var->nbr_of_philo)
		kill(var->pids[i++], SIGKILL);
	free(var->pids);
	if (var->max_meal != NO_NEED)
		make_sure_hes_dead(var);
	close_semaphore(var, 5);
	return (1);
}
