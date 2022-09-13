/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:24 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:36:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

/* Constructors and destructor */

AMateria::AMateria(void) : _type() {
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	std::cout << "AMateria parameterized constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) : _type(src._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

/* Assignment operator */

AMateria	&AMateria::operator=(AMateria const &rhs) {
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/* Member functions */
void	AMateria::use(ICharacter &target) {
	(void)target;
	return ;
}

/* Getter */

std::string const &AMateria::getType() const {
	return (this->_type);
}
