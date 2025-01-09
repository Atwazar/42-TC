/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:35:59 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/13 20:22:27 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_calloco(int len)
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
		next_line = ft_calloco(len);
		if (!next_line)
			return (0);
		next_line = ft_part_cpy(line, next_line, len);
	}
	else
	{
		next_line = ft_calloco((i + 2) * sizeof(char));
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

char	*get_next_line(int fd, int mode)
{
	static char	*line;
	char		*buffer;
	char		*next_line;

	if (!(BUFFER_SIZE > 0) || fd == -1 || mode)
	{
		if (line)
			return (free(line), NULL);
		return (0);
	}			
	if (!line)
	{
		line = ft_calloco(1);
		if (!line)
			return (0);
	}
	buffer = ft_calloco(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), NULL);
	line = read_line(fd, line, buffer);
	next_line = ft_create_line(line);
	line = prep_line(line, next_line);
	return (next_line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int	a;
	char	*b;

	if (ac!=2)
	{
		printf("LES ARGUMENTSSS");
		return (0);
	}
	a = open(av[1], O_RDONLY);
	while ((b = get_next_line(a)) != NULL)
	{
		printf("%s", b);
		free(b);
	}
	close(a);
}*/
