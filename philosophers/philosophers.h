/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:23:21 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 13:56:55 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* 0. EXTERNAL LIBRARIES */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

/* 1. MACROS */
# define ERROR_USAGE "Error!\nPlease use as follows: \
nbr_of_philo time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n"
# define WRONG_INPUT "Error!\nPlease enter valid input\n"
# define ERROR_INIT "Error!\nProblem occured during initialization\n"
# define PICK_UP_FORK 0
# define EAT	1
# define SLEEP 2
# define THINK 3
# define DIE 4

/* 2. CUSTOM STRUCTURES */
struct	s_param;

typedef struct s_thread
{
	pthread_t			thread_id;
	int					philosopher_id;
	int					fork_left;
	int					fork_right;
	int					ate;
	unsigned long int	last_meal;
	struct s_param		*param;
}			t_thread;

typedef struct s_param
{
	unsigned long int	start_clock;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	int					nbr_philo;
	int					flag_optional_arg;
	int					nbr_of_rounds;
	int					end;
	int					*fork_id;
	pthread_mutex_t		write;
	pthread_mutex_t		eat;
	pthread_mutex_t		*fork;
	t_thread			*thread;
}			t_param;

/* 3. FUNCTIONS */

/* 3.0 Main */
void			*start_routine(void *env);

/* 3.1 Initialization */
int				ft_check_input(int argc, char **argv);
int				init_param(t_param *param, int argc, char **argv);
int				init_mutexes(t_param *param, int i);
int				init_threads(t_param *param, int i);
int				exit_threads(t_param *param);

/* 3.2 Actions */
void			ft_log(t_param *param, int id, int mode);
void			pick_up_and_eat(t_thread *thread);
void			check_if_dying(t_param *param);

/* 3.3 Get time */
long long int	time_now(void);
void			custom_sleep(unsigned long int duration, t_param *param);

/* 3.4 Free heap memory */
int				free_param(t_param *param);
void			free_memory(t_param *param);
int				destroy_mutexes(t_param *param);
int				ft_error(char *error_msg);

/* 3.5 Utils */
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				ft_is_int(const char *nptr);
int				ft_atoi_zero(const char *nptr);

#endif
