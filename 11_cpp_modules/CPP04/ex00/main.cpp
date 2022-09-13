/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:48 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 14:28:20 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*i = new Cat();
	const Animal	*j = new Cat("Feta");
	const Animal	*k = new Dog();
	const Animal	*l = new Dog("Max");
	const WrongAnimal	*m = new WrongCat();
	const WrongAnimal	*n = new WrongCat("Josh");

	std::cout << "---------------- " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << m->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	std::cout << "---------------- " << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();
	l->makeSound();
	m->makeSound();
	n->makeSound();
	std::cout << "---------------- " << std::endl;
	
	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	delete m;
	delete n;

	return (0);
}
