/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:43 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 14:08:38 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

/* Constructors and destructor */

Brain::Brain(void)
{
	for (int i = 0; i < 100; i ++)
		this->_ideas[i] = "Idea #" + std::to_string(i);
	std::cout << "Default brain constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	for (int i = 0; i < 100; i ++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy base constructor called" << std::endl;
	return ;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Brain	&Brain::operator=(Brain const &rhs) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i ++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

/* Getter */
std::string		Brain::getIdeas(int i) const {
	return (this->_ideas[i]);
}
