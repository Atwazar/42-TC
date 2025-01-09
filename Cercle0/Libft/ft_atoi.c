/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:57:43 by thelaine          #+#    #+#             */
/*   Updated: 2024/03/28 15:22:41 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		sign;
	long	n;

	n = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (!(*str < '0' || *str > '9'))
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}

/*#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("mon atoi = %d \n", ft_atoi(argv[1]));
	printf("mon atoi = %d \n", atoi(argv[1]));
	return (0);
}*/
