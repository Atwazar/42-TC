/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:06:32 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/22 18:00:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countint(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	ft_writelong(nb);
	if (n == 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_countunsigned(unsigned int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	nb = n;
	ft_writelong(nb);
	if (n == 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	ft_counthexa(unsigned long n, char c)
{
	char	*base;
	int		len;

	len = 0;
	if (c == 'p')
	{
		if (n == 0)
			return (ft_putstr("(nil)"));
		len += ft_putstr("0x");
	}
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	ft_writehexa(n, base);
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
