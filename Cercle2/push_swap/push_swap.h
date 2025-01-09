/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:20:11 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/27 15:23:52 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_infomin
{
	int	pos_a;
	int	pos_b;
	int	len_a;
	int	len_b;
	int	nbr_mouv;
	int	mouv;
}	t_infomin;

# define RARB 0
# define RARRB 1
# define RRARB 2
# define RRARRB 3

//utils.c
int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str);

//checks.c
int			ft_isdigit(char c);
int			check_str(char *str);
int			check_split(char **splitted, int count);
int			check_tab(long	*tab);

//create_tablong.c
long		*free_create_tab(char **splitted, int ac);
long		*create_tab(char **splitted, int len, int ac);
long		ft_atoi(char *str);
long		*create_and_check(char **splitted, int count, int ac);
long		*create_tablong(int ac, char **av);

//utils_2.c
int			ft_strlcpy(char *dest, char *src, size_t n);
char		*ft_substr(char *str, int start, size_t len);
void		*ft_calloc(size_t nb_elem, size_t size_elem);
int			ft_lst_size(t_stack *a);
void		free_stack(t_stack **a);

//utils_3.c
int			highvalue_remains(t_stack *a, int q2);
int			ft_max(int x, int y);
int			ft_min(int x, int y);
void		msg_error(void);

//ft_split.c
int			ft_strreallen(char *s);
int			count_words(char *s);
void		free_split(char **splitted);
char		**ft_split(char *s, int count);

//create_stack.c
int			add_stack(t_stack **first_elem, int content);
t_stack		*create_stack(long *tab);

//find_quartiles.c
long		*sort_tab(long *tab);
int			find_quart(long *tab, int quart_number);

//rotate.c
void		rotate(t_stack **a, t_stack **b);

//rev_rotate.c
void		rev_rotate(t_stack **a, t_stack **b);

//swap.c
void		swap(t_stack **a, t_stack **b);

//push.c
void		push_empty(t_stack **src, t_stack **dest);
void		push_stack(t_stack **src, t_stack **dest);
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);

//short_sort.c
void		sort_2(t_stack **a);
void		sort_3(t_stack **a);
//pre_sort.c
void		pre_sort_short(t_stack **a, t_stack **b);
void		pre_sort_big(t_stack **a, t_stack **b, long *tab);
void		pre_sort(t_stack **a, t_stack **b, long *tab);

//find_elem_place.c
void		go_to_first_elem(t_stack **a);
int			find_elem_place(int content, t_stack *stack);

//find_best_rotate.c
void		clean_min(t_infomin **min_i);
t_infomin	*calculate_rotate(t_infomin *min_i, int pos_a, int pos_b);
t_infomin	*find_best_rotate(t_stack *a, t_stack *b);

//do_best_rotate.c
void		do_rarb(t_stack **a, t_stack **b, t_infomin *min_info);
void		do_rarrb(t_stack **a, t_stack **b, t_infomin *min_info);
void		do_rrarb(t_stack **a, t_stack **b, t_infomin *min_info);
void		do_rrarrb(t_stack **a, t_stack **b, t_infomin *min_info);
void		do_best_rotate(t_stack **a, t_stack **b, t_infomin *min_info);

//sort.c
int			is_sorted(t_stack *a);
void		sort(t_stack *a, long *tab);

//bonus

# define WRONG_MOUVEMENT 0
# define RA 1
# define RB 2
# define RR 3
# define RRA 4
# define RRB 5
# define RRR 6
# define PA 7
# define PB 8
# define SA 9
# define SB 10
# define SS 11

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*ft_calloco(int len);
char		*ft_create_line(char *line);
char		*ft_str_join(char *str1, char *str2);
char		*prep_line(char *line, char *next_line);
char		*ft_part_cpy(char *src, char *dest, int to);
char		*read_line(int fd, char *line, char *buffer);
char		*get_next_line(int fd, int mode);

int			ft_isinstr(char *str);
int			ft_len(char *str);

void		ft_bzero(void *ptr, int n);

//rotate_bonus.c
void		rotate_bonus(t_stack **a, t_stack **b);

//rev_rotate_bonus.c
void		rev_rotate_bonus(t_stack **a, t_stack **b);

//swap_bonus.c
void		swap_bonus(t_stack **a, t_stack **b);

//push_bonus.c
void		push_a_bonus(t_stack **a, t_stack **b);
void		push_b_bonus(t_stack **a, t_stack **b);

//push_swap_bonus.c
int			ft_strcmp(char *str1, char *str2);
int			check_command(char *command);
void		do_command(int command_nbr, t_stack **a, t_stack **b);
int			follow_the_code(t_stack **a, t_stack **b);

#endif
