/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:13:16 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:57:03 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

/* Constructors and destructor */

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src) {
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure::~Cure(void) {
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Cure	&Cure::operator=(Cure const &rhs) {
	std::cout << "Cure Copy assignment operator called" << std::endl;
	this->AMateria::operator=(rhs);
	return (*this);
}

/* Member functions */
AMateria	*Cure::clone() const {
	AMateria	*obj = new Cure(*this);
	return (obj);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
