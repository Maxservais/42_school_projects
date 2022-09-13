/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:58:33 by mservais          #+#    #+#             */
/*   Updated: 2022/03/10 16:16:16 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *tab, size_t arrSize, void (*f)(T &))
{
	size_t	i;

	i = 0;
	while (i < arrSize)
	{
		f(tab[i]);
		i++;
	}
	return ;
}

template<typename T>
void	iter(T *tab, size_t arrSize, void (*f)(const T &))
{
	size_t	i;

	i = 0;
	while (i < arrSize)
	{
		f(tab[i]);
		i++;
	}
	return ;
}

template<typename T>
void	multiply(T &x)
{
	x *= 2;
}

#endif
