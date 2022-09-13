/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:58:40 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 13:16:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_log(t_param *param, int id, int mode)
{
	pthread_mutex_lock(&param->write);
	if (!param->end)
	{
		if (mode == 0)
			printf("%lld %d has taken a fork\n",
				time_now() - param->start_clock, id);
		else if (mode == 1)
			printf("%lld %d is eating\n",
				time_now() - param->start_clock, id);
		else if (mode == 2)
			printf("%lld %d is sleeping\n",
				time_now() - param->start_clock, id);
		else if (mode == 3)
			printf("%lld %d is thinking\n",
				time_now() - param->start_clock, id);
		else if (mode == 4)
			printf("%lld %d died\n",
				time_now() - param->start_clock, id);
	}
	pthread_mutex_unlock(&param->write);
}

void	pick_up_and_eat(t_thread *thread)
{
	t_param	*param;

	param = thread->param;
	thread->fork_left = param->fork_id[thread->philosopher_id - 1];
	thread->fork_right = (thread->fork_left + 1) % param->nbr_philo;
	pthread_mutex_lock(&param->fork[thread->fork_left]);
	ft_log(param, thread->philosopher_id, PICK_UP_FORK);
	pthread_mutex_lock(&param->fork[thread->fork_right]);
	ft_log(param, thread->philosopher_id, PICK_UP_FORK);
	pthread_mutex_lock(&param->eat);
	ft_log(param, thread->philosopher_id, EAT);
	thread->last_meal = time_now();
	pthread_mutex_unlock(&param->eat);
	custom_sleep(param->time_to_eat, param);
	thread->ate++;
	pthread_mutex_unlock(&param->fork[thread->fork_right]);
	pthread_mutex_unlock(&param->fork[thread->fork_left]);
}

void	check_if_dying(t_param *param)
{
	int	i;

	while (!param->end)
	{
		i = -1;
		while (++i < param->nbr_philo && !param->end)
		{
			pthread_mutex_lock(&param->eat);
			if (time_now() - param->thread[i].last_meal >= param->time_to_die)
			{
				ft_log(param, param->thread[i].philosopher_id, DIE);
				pthread_mutex_lock(&param->write);
				param->end = 1;
			}
			pthread_mutex_unlock(&param->eat);
		}
		if (param->end)
			break ;
		i = 0;
		while (param->nbr_of_rounds && i < param->nbr_philo
			&& param->thread[i].ate >= param->nbr_of_rounds)
			i++;
		if (i == param->nbr_philo)
			param->end = 1;
	}
}
