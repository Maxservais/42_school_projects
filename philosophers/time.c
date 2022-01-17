/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:11:25 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 13:40:58 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long int	time_now(void)
{
	struct timeval		te;
	unsigned long int	time_in_ms;

	gettimeofday(&te, NULL);
	time_in_ms = (te.tv_sec * 1000) + (te.tv_usec / 1000);
	return (time_in_ms);
}

void	custom_sleep(unsigned long int duration, t_param *param)
{
	unsigned long int	start;

	start = time_now();
	while (!param->end)
	{
		if (time_now() - start >= duration)
			break ;
		usleep(param->nbr_philo * 2);
	}
}
