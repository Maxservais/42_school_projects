/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:37 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 11:08:55 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

/* Constructors and destructor */

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog parameterized constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Dog	&Dog::operator=(Dog const &rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Member functions */

void	Dog::makeSound(void) const {
	std::cout << "Waff Waff..." << std::endl;
	return ;
}
