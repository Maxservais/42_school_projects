/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:05:06 by mservais          #+#    #+#             */
/*   Updated: 2021/12/07 13:41:19 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_overflow(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((*(nptr + i) >= 9 && *(nptr + i) <= 13) || *(nptr + i) == 32)
		i++;
	if (*(nptr + i) == ' ' || *(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign = -1;
		i++;
	}
	while (*(nptr + i) != '\0' && ft_isdigit(*(nptr + i)))
	{
		if (res > LONG_MAX / 10)
			return (ft_overflow(sign));
		res = (10 * res) + (*(nptr + i) - '0');
		if (res < 0)
			return (ft_overflow(sign));
		i++;
	}
	return (sign * res);
}

int	ft_is_int(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((*(nptr + i) >= 9 && *(nptr + i) <= 13) || *(nptr + i) == 32)
		i++;
	if (*(nptr + i) == ' ' || *(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign = -1;
		i++;
	}
	while (*(nptr + i) != '\0')
	{
		if (!ft_isdigit(*(nptr + i)) || res > INT_MAX / 10)
			return (0);
		res = (10 * res) + (*(nptr + i) - '0');
		if (res < 0 && !(res == INT_MIN && sign == -1))
			return (0);
		i++;
	}
	return (sign * res);
}

int	ft_atoi_zero(const char *nptr)
{
	int	i;

	i = 0;
	if (*(nptr + i) == ' ' || *(nptr + i) == '-' || *(nptr + i) == '+')
		i++;
	while (*(nptr + i) == '0')
		i++;
	if (*(nptr + i) == '\0')
		return (0);
	return (1);
}
