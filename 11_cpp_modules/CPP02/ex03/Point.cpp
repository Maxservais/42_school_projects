/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:57:06 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 18:10:23 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructors and destructor */

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {
	return ;
}

Point::Point(float const a, float const b) : _x(Fixed(a)), _y(Fixed(b)) {
	return ;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {
	return ;
}

Point::~Point(void) {
	return ;
}

/* Assignment operator */

Point &Point::operator=(Point const &rhs) {
	(void)rhs;
	return (*this);
}

/* Getter and setter */

Fixed const	Point::getPosx(void) const {
	return (this->_x);
}

Fixed const	Point::getPosy(void) const {
	return (this->_y);
}