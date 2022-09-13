/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:57:08 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 17:54:08 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point {

	public:

		/* Constructors and destructor */
		Point(void);
		Point(float const a, float const b);
		Point(Point const &src);
		~Point(void);

		/* Assignment operator */
		Point	&operator=(Point const &rhs);

		/* Getter and setter */
		Fixed const	getPosx(void) const;
		Fixed const	getPosy(void) const;


	private:

		Fixed const	_x;
		Fixed const	_y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
