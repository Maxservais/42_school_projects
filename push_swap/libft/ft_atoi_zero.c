/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:19:10 by mservais          #+#    #+#             */
/*   Updated: 2021/10/13 10:39:23 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
