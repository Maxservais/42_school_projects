/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:00 by mservais          #+#    #+#             */
/*   Updated: 2022/02/21 16:06:02 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

/* Constructors and destructor */

WrongAnimal::WrongAnimal(void) : type("N/A")
{
	std::cout << "Default base constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Parameterized base constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : type(src.type)
{
	std::cout << "Copy base constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Base destructor called for: " << this->type << std::endl;
	return ;
}

/* Assignment operator */

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Member functions */

void	WrongAnimal::makeSound(void) const {
	std::cout << "*Generic WrongAnimal sound*" << std::endl;
	return ;
}

/* Getter */

std::string	WrongAnimal::getType(void) const {
	return (this->type);
}
