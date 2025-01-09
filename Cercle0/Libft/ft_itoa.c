/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:58:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 19:01:29 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_str(long nb)
{
	int		power;
	int		len;

	power = 10;
	len = 0;
	if (nb < 0)
	{
		len += 1;
		nb = -nb;
	}
	if (nb == 0)
		len += 1;
	while (nb)
	{
		len++;
		nb = nb / power;
	}
	return ((char *)ft_calloc(len + 1, sizeof(char)));
}

static void	copy_number(long nb, char *str)
{
	if (nb < 10)
	{
		str[ft_strlen(str)] = nb + '0';
	}
	else
	{
		copy_number(nb / 10, str);
		copy_number(nb % 10, str);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;

	nb = n;
	str = create_str(nb);
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	copy_number(nb, str);
	return (str);
}
/*int	main(void)
{
	int	i = -2147483648;
	printf("%s", ft_itoa(i));
}*/
