/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:18 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:29:17 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define N 4

int	main(void)
{
	/* Array of N elements where each element is
	a pointer to an object of type Animal */
	Animal	*arr[N];

	/* Fill an array of pointers to Animal objects */
	for (int k = 0; k < N; k++)
	{
		if (k < N / 2)
			arr[k] = new Cat();
		else
			arr[k] = new Dog();
	}

	std::cout << "---------------- " << std::endl;
	std::cout << arr[3]->getType() << std::endl;
	arr[3]->makeSound();
	std::cout << "---------------- " << std::endl;

	/* Deep copy of one of the instances */
	Cat	cpy = *(Cat *)arr[1];

	/* Delete all Animal instances */
	std::cout << "---------------- " << std::endl;
	for (int k = 0; k < N; k++)
		delete arr[k];

	/* Verify copy worked */
	std::cout << "---------------- " << std::endl;
	cpy.makeSound();
	std::cout << cpy.getType() << std::endl;
	std::cout << cpy.getBrain()->getIdeas(1) << std::endl;
	std::cout << "---------------- " << std::endl;
	return (0);
}
