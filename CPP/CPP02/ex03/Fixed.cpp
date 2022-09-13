/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:45:01 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 16:26:39 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

/* Constructors and destructor */

Fixed::Fixed(void) : _fixed(0) {
	return ;
}

Fixed::Fixed(int const nbr) : _fixed(nbr << _nbBits) {
	return ;
}

Fixed::Fixed(float const nbr) : _fixed(roundf(nbr * (1 << _nbBits))) {
	return ;
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

/* Assignment operator */

Fixed &Fixed::operator=(Fixed const &rhs) {
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return (*this);
}

/* Comparison operators */

bool	Fixed::operator>(Fixed const &rhs) {
	return(this->_fixed > rhs._fixed);
}

bool	Fixed::operator<(Fixed const &rhs) {
	return(this->_fixed < rhs._fixed);
}

bool	Fixed::operator>=(Fixed const &rhs) {
	return (this->_fixed >= rhs._fixed);
}

bool	Fixed::operator<=(Fixed const &rhs) {
	return (this->_fixed <= rhs._fixed);
}

bool	Fixed::operator==(Fixed const &rhs) {
	return (this->_fixed == rhs._fixed);
}

bool	Fixed::operator!=(Fixed const &rhs) {
	return (this->_fixed != rhs._fixed);
}

/* Arithmetic operators (+,-,*,/) */

Fixed	Fixed::operator+(Fixed const &rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_fixed + rhs._fixed);
	return (ret);
	// return Fixed((this->_fixed + rhs._fixed) >> _nbBits);
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_fixed - rhs._fixed);
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_fixed * rhs._fixed >> _nbBits);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_fixed * (1 << _nbBits) / rhs._nbBits);
	return (ret);
}

/* Increment and decrement operators */

Fixed	&Fixed::operator++(void) {
	this->_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp;
	tmp._fixed = this->_fixed++;
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

/* Public Member functions */

int		Fixed::toInt(void) const {
	return (this->_fixed >> _nbBits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixed / (double)(1 << _nbBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a._fixed > b._fixed)
		return (b);
	else
		return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

/* Getter and setter */

int		Fixed::getRawBits(void) const {
	return this->_fixed;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
	return ;
}

/* Insertion operator */

std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}

int const	Fixed::_nbBits = 8;
