/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:43 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:04:26 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

/* Constructors and destructor */

AAnimal::AAnimal(void) : type("N/A")
{
	std::cout << "Default base constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Parameterized base constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src) : type(src.type)
{
	std::cout << "Copy base constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal(void) {
	std::cout << "Base destructor called for: " << this->type << std::endl;
	return ;
}

/* Assignment operator */

AAnimal	&AAnimal::operator=(AAnimal const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Getter */

std::string	AAnimal::getType(void) const {
	return (this->type);
}
