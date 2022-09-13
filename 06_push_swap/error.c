/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:20:19 by mservais          #+#    #+#             */
/*   Updated: 2021/11/08 12:55:01 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_message(void)
{
	write(1, "Error\n", ft_strlen("Error\n"));
	return (1);
}

int	find_errors(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		if (ft_atoi_overflow(argv[i]) == 0 && ft_atoi_zero(argv[i]) == 1)
			return (1);
		while (j < argc)
		{
			if (ft_atoi_overflow(argv[i]) == ft_atoi_overflow(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
