/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:07 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:05 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

/* Constructors and destructor */

Dog::Dog(void) : AAnimal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(std::string type) : AAnimal(type) {
	this->_brain = new Brain();
	std::cout << "Dog parameterized constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : AAnimal(src) {
	if (src._brain)
		this->_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

/* Getter */
Brain	*Dog::getBrain(void) const {
	return (this->_brain);
}

/* Member functions */

void	Dog::makeSound(void) const {
	std::cout << "Waff Waff..." << std::endl;
	return ;
}
