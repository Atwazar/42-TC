/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <theo.helaine@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:41:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/05/21 17:15:27 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_itoa(int n);
char	*ft_strchr(const char *str, int val);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *tofind, size_t n);
char	*ft_strrchr(const char *str, int val);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
int		ft_strlcat(char *dest, const char *src, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

size_t	ft_strlen(const char *str);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);

void	ft_bzero(void *ptr, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

void	*ft_calloc(size_t nb_elem, size_t size_elem);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *ptr, int val, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int val, size_t n);

#endif
