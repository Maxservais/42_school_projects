/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:21:57 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:02:05 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

/* Constructors and destructor */

Character::Character(void) : _name("Undefined") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string const &name) : _name(name) {
	std::cout << "Character parameterized constructor called for " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(Character const &src) : _name(src._name) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
	return ;
}

/* Assignment operator */

Character	&Character::operator=(Character const &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character Copy assignment operator called" << std::endl;
	return (*this);
}

/* Member functions */

void	Character::equip(AMateria *m) {
	if (!m)
	{
		std::cout << "Materia couldn't be added to inventory!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Materia added to inventory at index " << i << std::endl;
			return ;
		}
	}
	std::cout << "Materia couldn't be added to inventory, no space left!" << std::endl;
	return ;
}

void	Character::unequip(int idx) {
	if (idx > 3 || idx < 0) {
		std::cout << "Inventory only has 4 slots, index must be between 0 and 3!" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
		std::cout << "No Materia in inventory at index " << idx << std::endl;
	else
	{
		this->_inventory[idx] = NULL;
		std::cout << "Materia at index " << idx << " was removed from inventory" << std::endl;
	}
	return ;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx > 3 || idx < 0 || !this->_inventory[idx])
	{
		std::cout << "No materia to be used at index " << idx << std::endl;
		return ;
	}
	else
		this->_inventory[idx]->use(target);
	return ;
}

/* Getter */

std::string	const	&Character::getName() const {
	return (this->_name);
}
