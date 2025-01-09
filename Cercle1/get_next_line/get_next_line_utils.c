/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:39:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/02 18:26:25 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_part_cpy(char *src, char *dest, int to)
{
	int	i;
	int	j;

	i = 0;
	j = ft_len(dest);
	if (!src)
		return (0);
	while (i < to)
	{
		dest[i + j] = src[i];
		i ++;
	}
	return (dest);
}

void	ft_bzero(void *ptr, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ptr;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_str_join(char *line, char *buffer)
{
	char	*final_str;
	int		len_buffer;
	int		len_line;

	len_buffer = ft_len(buffer);
	len_line = ft_len(line);
	final_str = ft_calloc(len_line + len_buffer + 1);
	if (!final_str)
	{
		free(line);
		return (0);
	}
	final_str = ft_part_cpy(line, final_str, len_line);
	final_str = ft_part_cpy(buffer, final_str, len_buffer);
	free(line);
	return (final_str);
}

int	ft_isinstr(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
