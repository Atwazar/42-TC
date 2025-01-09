/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:35:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/03 11:58:02 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(int len)
{
	char	*str;

	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	ft_bzero(str, len);
	return (str);
}

char	*ft_create_line(char *line)
{
	char	*next_line;
	int		i;
	int		len;

	if (!line)
		return (0);
	i = ft_isinstr(line);
	if (i == -1)
	{
		len = ft_len(line) + 1;
		if (len == 1)
			return (0);
		next_line = ft_calloc(len);
		if (!next_line)
			return (0);
		next_line = ft_part_cpy(line, next_line, len);
	}
	else
	{
		next_line = ft_calloc((i + 2) * sizeof(char));
		if (!next_line)
			return (0);
		next_line = ft_part_cpy(line, next_line, i + 1);
	}
	return (next_line);
}

char	*prep_line(char *line, char *next_line)
{
	char	*save;
	int		i;
	int		len;

	i = ft_isinstr(line);
	len = ft_len(line);
	save = 0;
	if (next_line && i != -1)
	{
		save = malloc((len - i + 1) * sizeof(char));
		if (!save)
		{
			if (next_line)
				free(next_line);
			free(line);
			return ("\0");
		}
		ft_bzero(save, len - i + 1);
		save = ft_part_cpy(line + i + 1, save, len - i);
	}
	free(line);
	return (save);
}

char	*read_line(int fd, char *line, char *buffer)
{
	int	check_read;

	check_read = BUFFER_SIZE;
	while (check_read == BUFFER_SIZE && ft_isinstr(line) == -1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		check_read = read(fd, buffer, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(line);
			free(buffer);
			return (0);
		}
		line = ft_str_join(line, buffer);
		if (!line)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*next_line;

	if (!(BUFFER_SIZE > 0) || fd == -1)
		return (0);
	if (!line)
	{
		line = ft_calloc(1);
		if (!line)
			return (0);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(line);
		return (0);
	}
	line = read_line(fd, line, buffer);
	next_line = ft_create_line(line);
	line = prep_line(line, next_line);
	return (next_line);
}
