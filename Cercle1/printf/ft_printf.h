/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:41:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/22 18:00:04 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);

int		ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_putpercent(void);

int		ft_countint(int n);
int		ft_counthexa(unsigned long n, char c);
int		ft_countunsigned(unsigned int n);

int		ft_specialcases(char c, va_list ap);
int		ft_printf(const char *str, ...);

void	ft_writelong(long n);
void	ft_writehexa(unsigned long n, char *base);

#endif
