/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:08 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 15:13:00 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = nbr << _nbBits;
	return ;
}

Fixed::Fixed(float const nbr) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(nbr * (1 << _nbBits));
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return ;
}

int		Fixed::toInt(void) const {
	return (this->_fixed >> _nbBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixed / (double)(1 << _nbBits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return (o);
}

int const	Fixed::_nbBits = 8;
