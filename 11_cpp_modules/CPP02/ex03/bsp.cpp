/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:00:07 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 18:05:41 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Credit: https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle */

#include "Point.hpp"

float sign (Point p1, Point p2, Point p3)
{
	return ((p1.getPosx().toFloat() - p3.getPosx().toFloat()) * (p2.getPosy().toFloat() - p3.getPosy().toFloat())
			- (p2.getPosx().toFloat() - p3.getPosx().toFloat()) * (p1.getPosy().toFloat() - p3.getPosy().toFloat()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	d1;
	float	d2;
	float	d3;
	bool 	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
