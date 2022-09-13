/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:53:17 by mservais          #+#    #+#             */
/*   Updated: 2022/03/10 14:53:22 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &left, T &right)
{
	T	tmp(left);

	left = right;
	right = tmp;
	return ;
}

template<typename T>
T const	&max(T const &left, T const &right)
{
	return ((left > right) ? left : right);
}

template<typename T>
T const	&min(T const &left, T const &right)
{
	return ((left < right) ? left : right);
}

#endif
