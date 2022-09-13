/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:04 by mservais          #+#    #+#             */
/*   Updated: 2022/02/21 16:05:09 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

/* Constructors and destructor */

Animal::Animal(void) : type("N/A")
{
	std::cout << "Default base constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Parameterized base constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &src) : type(src.type)
{
	std::cout << "Copy base constructor called" << std::endl;
	return ;
}

Animal::~Animal(void) {
	std::cout << "Base destructor called for: " << this->type << std::endl;
	return ;
}

/* Assignment operator */

Animal	&Animal::operator=(Animal const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Member functions */

void	Animal::makeSound(void) const {
	std::cout << "*Generic animal sound*" << std::endl;
	return ;
}

/* Getter */

std::string	Animal::getType(void) const {
	return (this->type);
}
