/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:34:45 by thelaine          #+#    #+#             */
/*   Updated: 2024/06/03 11:58:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 

# include <stdlib.h>
# include <unistd.h>

char	*ft_calloc(int len);
char	*ft_create_line(char *line);
char	*ft_str_join(char *str1, char *str2);
char	*prep_line(char *line, char *next_line);
char	*ft_part_cpy(char *src, char *dest, int to);
char	*read_line(int fd, char *line, char *buffer);
char	*get_next_line(int fd);

int		ft_isinstr(char *str);
int		ft_len(char *str);

void	ft_bzero(void *ptr, int n);

#endif
