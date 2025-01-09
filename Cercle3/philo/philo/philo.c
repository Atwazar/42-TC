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

	var.philos = 0;
	var.state = CONTINUE;
	if (!check_args(ac, av, &var) || !create_philo_table(&var)
		|| !create_philo_thread(&var))
		return (0);
	monitor(&var);
	return (1);
}
