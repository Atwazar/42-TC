/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:33:14 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 20:34:39 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_var	var;

	var.nbr_of_meal = 0;
	var.time_of_last_meal = 0;
	if (!check_args(ac, av, &var))
		return (0);
	if (!create_philo_table(&var))
		return (0);
	if (!do_the_simulation(&var))
		return (0);
	return (1);
}
