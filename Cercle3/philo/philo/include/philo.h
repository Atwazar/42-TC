/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:20:47 by thelaine          #+#    #+#             */
/*   Updated: 2024/07/28 20:26:47 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647

typedef enum e_data
{
	NBR_OF_PHILO = 1,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MAX_MEAL,
}	t_data;

typedef enum e_action
{
	TAKE_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED,
}	t_action;

# define NO_NEED -1
# define TRUE 0
# define FALSE 1

# define CONTINUE 0
# define END 1

# define LONELY_PHILO 0

# define CONVERT 1000

typedef struct s_philos
{
	int				philo_id;
	pthread_mutex_t	fork;
	struct s_philos	*next;
	struct s_philos	*prev;
	pthread_mutex_t	*favorite_fork;
	pthread_mutex_t	*meh_fork;
	pthread_mutex_t	no_modifs;
	long			time_of_last_meal;
	long			actual_time;
	long			*starting_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nbr_of_meals;
	int				nbr_of_philos;
	int				*state;
	pthread_mutex_t	*speaking_totem;
	pthread_mutex_t	*can_change;
}	t_philos;

typedef struct s_var
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	long			starting_time;
	long			actual_time;
	int				state;
	t_philos		*philos;
	pthread_t		*philo_threads;
	pthread_mutex_t	speaking_totem;
	pthread_mutex_t	can_change;
}	t_var;

//definitly_not_lib_ft
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
long	ft_atoi(char *str);

//check_args.c
int		check_args(int ac, char **av, t_var *var);

//get_actual_time.c
long	get_time(void);
void	ft_usleep(long time);
void	update_time_last_meal(t_philos *philo);

//just_cleaning.c
void	free_philos(t_var *var);
void	join_threads(t_var *var, int threads_created);

//create_philo_table.c
int		create_philo_table(t_var *var);

//monitor.c
void	monitor(t_var *var);

//speak.c
void	speak(t_philos *philo, t_action action);

//routine.c
void	*fake_routine(void *philo_ptr);
void	*routine(void *philo_ptr);

//create_philo_thread.c
int		create_philo_thread(t_var *var);
#endif
