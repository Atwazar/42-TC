/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:52:27 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 20:52:53 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_ac(int ac)
{
	if (ac < 5)
		return (ft_putstr_fd("not enough arguments were given\n", 2), 0);
	if (ac > 6)
		return (ft_putstr_fd("too many arguments were given\n", 2), 0);
	return (1);
}

static int	check_av_content(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i] || !av[i][j])
			return (ft_putstr_fd("a null was given as arguments\n", 2), 0);
		while (av[i][j])
		{
			if (av[i][j] > '9' || av[i][j] < '0')
			{
				ft_putstr_fd("arguments not made of ", 2);
				return (ft_putstr_fd("positives numbers\n", 2), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_number(char *str, int *dest)
{
	long	number;

	number = ft_atoi(str);
	if (number > MAX_INT || number <= 0)
		return (0);
	*dest = (int)number;
	return (1);
}

static int	init_data_params(int ac, char **av, t_var *var)
{
	if (!check_number(av[NBR_OF_PHILO], &var->nbr_of_philo))
		return (ft_putstr_fd("number of philo is not an int > 0\n", 2), 0);
	if (!check_number(av[TIME_TO_DIE], &var->time_to_die))
		return (ft_putstr_fd("time to die is not an int > 0\n", 2), 0);
	if (!check_number(av[TIME_TO_EAT], &var->time_to_eat))
		return (ft_putstr_fd("time to eat is not an int > 0\n", 2), 0);
	if (!check_number(av[TIME_TO_SLEEP], &var->time_to_sleep))
		return (ft_putstr_fd("time to sleep is not an int > 0\n", 2), 0);
	if (ac == 6)
	{
		if (!check_number(av[MAX_MEAL], &var->max_meal))
			return (ft_putstr_fd("max meal is not an int > 0\n", 2), 0);
	}
	else
		var->max_meal = NO_NEED;
	return (1);
}

int	check_args(int ac, char **av, t_var *var)
{
	if (!check_ac(ac) || !check_av_content(ac, av))
		return (0);
	if (!init_data_params(ac, av, var))
		return (0);
	var->owns = var->nbr_of_philo / 2;
	return (1);
}
