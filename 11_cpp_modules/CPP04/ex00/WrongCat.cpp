/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:20 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 11:09:20 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

/* Constructors and destructor */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") 
{
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat parameterized constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

/* Assignment operator */

WrongCat	&WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

/* Member functions */

void	WrongCat::makeSound(void) const {
	std::cout << "Miaouw Miaouw..." << std::endl;
	return ;
}
