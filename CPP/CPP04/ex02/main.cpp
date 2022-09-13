/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:18 by mservais          #+#    #+#             */
/*   Updated: 2022/03/15 10:25:01 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define N 4

int	main(void)
{
	/* Not allowed */
	// const AAnimal	*meta = new AAnimal();
	const AAnimal	*i = new Cat();
	const AAnimal	*l = new Dog("Max");

	std::cout << "---------------- " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << "---------------- " << std::endl;

	i->makeSound();
	l->makeSound();
	std::cout << "---------------- " << std::endl;
	
	delete i;
	delete l;

	return (0);
}
