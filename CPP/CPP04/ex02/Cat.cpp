/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:55 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:14 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

/* Constructors and destructor */

Cat::Cat(void) : AAnimal("Cat") 
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(std::string type) : AAnimal(type) {
	this->_brain = new Brain();
	std::cout << "Cat parameterized constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : AAnimal(src) {
	if (src._brain)
		this->_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Cat	&Cat::operator=(Cat const &rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

/* Getter */
Brain	*Cat::getBrain(void) const {
	return (this->_brain);
}

/* Member functions */

void	Cat::makeSound(void) const {
	std::cout << "Miaouw Miaouw..." << std::endl;
	return ;
}
