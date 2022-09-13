/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:24 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 11:09:04 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

/* Constructors and destructor */

Cat::Cat(void) : Animal("Cat") 
{
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat parameterized constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Member functions */

void	Cat::makeSound(void) const {
	std::cout << "Miaouw Miaouw..." << std::endl;
	return ;
}
