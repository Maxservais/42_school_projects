/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:06:05 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 14:36:05 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_param(t_param *param)
{
	free(param);
	return (-1);
}

void	free_memory(t_param *param)
{
	free(param->fork_id);
	free(param->fork);
	free(param);
}

int	destroy_mutexes(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->nbr_philo)
		pthread_mutex_destroy(&param->fork[i]);
	pthread_mutex_destroy(&param->eat);
	pthread_mutex_destroy(&param->write);
	return (0);
}

int	ft_error(char *error_msg)
{
	printf("%s", error_msg);
	return (EXIT_FAILURE);
}
