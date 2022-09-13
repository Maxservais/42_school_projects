/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:44:28 by mservais          #+#    #+#             */
/*   Updated: 2022/03/14 13:54:49 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(10);
	
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		const int value = rand();
		numbers[i] = value;
	}
	Array<int> tmp = numbers;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": [" << numbers[i] << "]" << std::endl;
		std::cout << i << ": [" << tmp[i] << "]" << std::endl;
	}
	try
	{
		numbers[5] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
