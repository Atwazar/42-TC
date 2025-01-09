/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:08:43 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/30 14:09:06 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	close_semaphore(t_var *var, int nbr_of_sem_created)
{
	if (nbr_of_sem_created > 0)
		sem_close(var->forks);
	if (nbr_of_sem_created > 1)
		sem_close(var->state);
	if (nbr_of_sem_created > 2)
		sem_close(var->forks_owners);
	if (nbr_of_sem_created > 3)
		sem_close(var->speaking_totem);
	if (nbr_of_sem_created > 4 && var->max_meal != NO_NEED)
		sem_close(var->ate_enough);
}
