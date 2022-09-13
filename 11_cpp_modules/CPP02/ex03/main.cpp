/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:28:24 by mservais          #+#    #+#             */
/*   Updated: 2022/02/16 18:09:51 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	const Point a(1.f, 0.f);
	const Point b(12.f, 0.f);
	const Point c(2.f, 10.f);
	const Point p1(2.f, 2.f);
	const Point p2(-1.f, 0.f);
	
	if (bsp(a, b, c, p1))
		std::cout <<"Inside" << std::endl;
	else
		std::cout <<"Not Inside" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout <<"Inside" << std::endl;
	else
		std::cout <<"Not Inside" << std::endl;
	return (0);
}
