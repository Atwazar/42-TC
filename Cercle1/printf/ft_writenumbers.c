/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:11:09 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/22 15:57:05 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writelong(long n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{	
		ft_writelong(n / 10);
		ft_writelong(n % 10);
	}
}

void	ft_writehexa(unsigned long n, char *base)
{
	if (n < 16)
		write(1, &base[n], 1);
	else
	{	
		ft_writehexa(n / 16, base);
		ft_writehexa(n % 16, base);
	}
}
