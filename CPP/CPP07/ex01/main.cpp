/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:39:59 by mservais          #+#    #+#             */
/*   Updated: 2022/03/14 14:00:47 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

void	print(const int& x)
{
	std::cout << x << std::endl;
}

void	add(int &x)
{
	x = x + 1;
}

#include <stdlib.h>
int	main(void)
{
	int	arr[12];

	for (size_t i = 0; i < 12; i++)
		arr[i] = i;
	std::cout << arr[0] << std::endl;
	::iter(arr, 12, add);
	std::cout << arr[0] << std::endl;
	::iter(arr, 12, multiply<int>);
	std::cout << arr[0] << std::endl;
	::iter(arr, 12, multiply<int>);
	std::cout << arr[0] << std::endl;
	::iter(arr, 12, add);
	std::cout << arr[0] << std::endl;
	
	std::cout << "-----Printing-----" << std::endl;
	::iter(arr, 12, print);

	return (0);
}