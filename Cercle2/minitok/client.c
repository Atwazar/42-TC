/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:29:29 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/18 16:05:07 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	count_received_char(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr(received);
		ft_putchar('\n');
		exit(0);
	}
}



static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i)
		{
			i--;
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i)
	{
		i--;
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr("wrong number of argument\n");
		return (1);
	}
	ft_putstr("Sent    : ");
	ft_putnbr(ft_strlen(argv[2]));
	ft_putchar('\n');
	ft_putstr("Received: ");
	signal(SIGUSR1, count_received_char);
	signal(SIGUSR2, count_received_char);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

