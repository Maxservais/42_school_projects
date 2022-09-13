/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:31:05 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:12:19 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "-------------Instantiation-------------\n"<< std::endl;
	ICharacter	*me = new Character("me");
	ICharacter	*bob = new Character("bob");
	std::cout << std::endl;
	
	IMateriaSource	*src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;
	
	AMateria	*cure = new Cure();
	src->learnMateria(cure);
	std::cout << std::endl;

	AMateria	*tmp = src->createMateria("ice");
	std::cout << std::endl;

	AMateria	*tmp1 = src->createMateria("cure");
	std::cout << std::endl;

	// AMateria	*tmp2 = src->createMateria("coucou");
	// std::cout << std::endl;

	std::cout << "-------------Game-------------\n"<< std::endl;
	me->equip(tmp);
	me->equip(tmp1);
	// me->equip(tmp2);

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	
	me->unequip(1);
	std::cout << std::endl;
	
	std::cout << "-------------Destructors-------------\n"<< std::endl;
	delete(tmp1);
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	return (0);
}
