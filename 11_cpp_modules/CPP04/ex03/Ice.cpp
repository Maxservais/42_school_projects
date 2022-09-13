/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:13:11 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:39:18 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

/* Constructors and destructor */

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src) {
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice::~Ice(void) {
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Ice	&Ice::operator=(Ice const &rhs) {
	std::cout << "Ice Copy assignment operator called" << std::endl;
	this->AMateria::operator=(rhs);
	return (*this);
}

/* Member functions */
AMateria	*Ice::clone() const {
	AMateria	*obj = new Ice(*this);
	return (obj);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
