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
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

# define MAX_INT 2147483647

# define NBR_OF_PHILO 1
# define TIME_TO_DIE 2
# define TIME_TO_EAT 3
# define TIME_TO_SLEEP 4
# define MAX_MEAL 5

# define TAKE_FORK 0
# define IS_EATING 1
# define IS_SLEEPING 2
# define IS_THINKING 3
# define DIED 4

# define NO_NEED -1
# define TRUE 0
# define FALSE 1

# define CONTINUE 0
# define END 1

# define LONELY_PHILO 0

# define CANT_SPEAK 0
# define CAN_SPEAK 1

# define CONVERT 1000

# define SHARED 1

typedef struct s_var
{
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			owns;
	int			max_meal;
	int			philo_id;
	int			nbr_of_meal;
	long		starting_time;
	long		time;
	long		time_of_last_meal;
	pid_t		*pids;
	sem_t		*forks;
	sem_t		*state;
	sem_t		*forks_owners;
	sem_t		*speaking_totem;
	sem_t		*ate_enough;
	sem_t		*dont_change;
	pthread_t	life_monitor;
}	t_var;

//definitly_not_lib_ft
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
long	ft_atoi(char *str);

//check_args.c
int		check_args(int ac, char **av, t_var *var);

//get_actual_time.c
void	init_time(t_var *var);
void	get_actual_time(t_var *philo);
long	get_time(t_var *philo);
void	update_time_last_meal(t_var *philo);

//just_cleaning.c
void	close_semaphore(t_var *var, int nbr_of_sem_created);

//create_philo_table.c
int		create_philo_table(t_var *var);

//monitor.c
void	make_sure_hes_dead(t_var *var);
int		create_monitor(t_var *var);

//speak.c
void	speak(t_var *philo, int action);

//routine.c
void	fake_routine(t_var *philo);
void	routine(t_var *philo);

//create_philo_thread.c
int		do_the_simulation(t_var *var);
#endif
