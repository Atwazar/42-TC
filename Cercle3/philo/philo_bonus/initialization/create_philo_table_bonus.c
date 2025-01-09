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

static void	sem_error(void)
{
	ft_putstr_fd("Error during semaphore creation\n", 2);
}

int	create_philo_table(t_var *var)
{
	sem_unlink("/forks");
	sem_unlink("/state");
	sem_unlink("/owners");
	sem_unlink("/speak");
	sem_unlink("/ate_enough");
	var->forks = sem_open("/forks", O_CREAT | O_EXCL, 0666, var->nbr_of_philo);
	if (!var->forks)
		return (sem_error(), close_semaphore(var, 0), 0);
	var->state = sem_open("/state", O_CREAT | O_EXCL, 0666, CONTINUE);
	if (!var->forks)
		return (sem_error(), close_semaphore(var, 1), 0);
	var->forks_owners = sem_open("/owners", O_CREAT | O_EXCL, 0666, var->owns);
	if (!var->forks)
		return (sem_error(), close_semaphore(var, 2), 0);
	var->speaking_totem = sem_open("/speak", O_CREAT | O_EXCL, 0666, CAN_SPEAK);
	if (!var->forks)
		return (sem_error(), close_semaphore(var, 3), 0);
	if (var->max_meal != NO_NEED)
	{
		var->ate_enough = sem_open("/ate_enough", O_CREAT | O_EXCL, 0666, 0);
		if (!var->ate_enough)
			return (sem_error(), close_semaphore(var, 4), 0);
	}
	return (1);
}
