/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:15:31 by mservais          #+#    #+#             */
/*   Updated: 2021/10/13 11:48:41 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_overflow(const char *nptr)
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
