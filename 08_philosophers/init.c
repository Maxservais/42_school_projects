/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:34:01 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 14:12:47 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Check if command-line arguments are valid */
int	ft_check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_int(argv[i]) == 0 && ft_atoi_zero(argv[i]) == 1)
			return (-1);
		if (ft_atoi(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

/* Initialize param */
int	init_param(t_param *param, int argc, char **argv)
{
	param->end = 0;
	param->start_clock = time_now();
	param->nbr_philo = ft_atoi(argv[1]);
	if (param->nbr_philo < 1)
	{
		free(param);
		return (-1);
	}
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		param->flag_optional_arg = 1;
		param->nbr_of_rounds = ft_atoi(argv[5]);
	}
	else
	{
		param->flag_optional_arg = 0;
		param->nbr_of_rounds = 0;
	}
	return (0);
}

/* Initialize our mutexes */
int	init_mutexes(t_param *param, int i)
{
	param->fork = malloc(sizeof(pthread_mutex_t) * param->nbr_philo);
	if (!param->fork)
		return (free_param(param));
	param->fork_id = malloc(sizeof(int) * param->nbr_philo);
	if (!param->fork_id)
	{
		free(param->fork);
		return (free_param(param));
	}
	while (++i < param->nbr_philo)
	{
		param->fork_id[i] = i;
		if (pthread_mutex_init(&param->fork[i], NULL) != 0)
		{
			free_memory(param);
			return (-1);
		}
	}
	if (pthread_mutex_init(&param->write, NULL)
		|| pthread_mutex_init(&param->eat, NULL))
	{
		free_memory(param);
		return (-1);
	}
	return (0);
}

/* Initialize our threads (our philosophers) */
int	init_threads(t_param *param, int i)
{
	param->thread = malloc(sizeof(t_thread) * param->nbr_philo);
	if (!param->thread)
	{
		free_memory(param);
		return (-1);
	}
	while (++i < param->nbr_philo)
	{
		param->thread[i].param = param;
		param->thread[i].philosopher_id = i + 1;
		param->thread[i].ate = 0;
		param->thread[i].last_meal = time_now();
		if (pthread_create(&param->thread[i].thread_id, NULL,
				&start_routine, (void *)&param->thread[i]) != 0)
		{
			free(param->thread);
			free_memory(param);
			return (-1);
		}
	}
	if (exit_threads(param))
		return (-1);
	return (0);
}

int	exit_threads(t_param *param)
{
	int	i;

	check_if_dying(param);
	pthread_mutex_unlock(&param->write);
	if (param->nbr_philo == 1)
		pthread_detach(param->thread[0].thread_id);
	else
	{
		i = 0;
		while (i < param->nbr_philo)
		{
			if (pthread_join(param->thread[i].thread_id, NULL) != 0)
			{
				free(param->thread);
				free_memory(param);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}
