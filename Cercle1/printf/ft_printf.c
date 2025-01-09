/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:10:15 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/05 13:42:59 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specialcases(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
	{
		i += ft_putstr(va_arg(ap, char *));
	}
	else if (c == 'p')
		i += ft_counthexa(va_arg(ap, unsigned long), c);
	else if (c == 'd' || c == 'i')
		i += ft_countint(va_arg(ap, int));
	else if (c == 'u')
		i += ft_countunsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		i += ft_counthexa(va_arg(ap, unsigned int), c);
	else if (c == 'X')
		i += ft_counthexa(va_arg(ap, unsigned int), c);
	else if (c == '%')
		i += ft_putpercent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_specialcases(*(str + 1), ap);
			str++;
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}

int main(void)
{
	int *p;
	int a = 0;
	int	i;
	int	j;
	void *ptr = NULL;
	p = &a;
	char *c = NULL;
	i = ft_printf("%s",c);
	printf("\n");
	j = printf("%s",c);
	printf("\n ft : %d\n vre : %d", i, j);
	return (0);
}
