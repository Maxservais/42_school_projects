/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:35:35 by mservais          #+#    #+#             */
/*   Updated: 2022/03/15 11:45:21 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
	public :
		virtual const char *what() const throw()
		{
			return ("Not found!");
		}
} ;

template<typename T>
void	easyfind(T	&cont, int nbr)
{
	typename T::iterator	itr;

	itr = std::find(cont.begin(), cont.end(), nbr);
	if (itr != cont.end())
		std::cout << "Found occurence: " << *itr << std::endl;
	else
		throw(NotFoundException());	
	return ;
}

#endif
