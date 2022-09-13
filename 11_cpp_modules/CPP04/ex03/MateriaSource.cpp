/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:44:54 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:07:03 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

/* Constructors and destructor */

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return ;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	return ;
}

/* Assignment operator */

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->~MateriaSource();
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

/* Member functions */

void	MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Learned new Materia" << std::endl;
			return ;
		}
	}
	std::cout << "Could not learn new Materia" << std::endl;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << "Created new Materia" << std::endl;
			return this->_inventory[i]->clone();
		}
	}
	std::cout << "Could not create new Materia" << std::endl;
	return (NULL);
}
