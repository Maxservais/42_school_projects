/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:30:36 by mservais          #+#    #+#             */
/*   Updated: 2021/06/01 18:36:11 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;
	unsigned char	my_c;

	i = 0;
	my_c = (unsigned char)c;
	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	if (n == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		if (*(ptr_src + i) == my_c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
