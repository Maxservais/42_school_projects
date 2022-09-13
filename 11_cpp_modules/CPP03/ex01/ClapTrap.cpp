/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:08:21 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 14:41:12 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/* Constructors and destructor */

ClapTrap::ClapTrap(void) :
_name("N/A"),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0)
{
	std::cout << "Default base constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : 
_name(name),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0)
{
	std::cout << "Parameterized base constructor called for " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) :
_name(src._name),
_hitPoint(src._hitPoint),
_energyPoint(src._energyPoint),
_attackDamage(src._attackDamage)
{
	std::cout << "Copy base constructor called for " << src._name << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Base destructor called for " << this->_name << std::endl;
	return ;
}

/* Assignment operator */

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoint = rhs._energyPoint;
	}
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return (*this);
}

/* Member functions */

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << this->_name << " has " << this->_energyPoint << " energy points left.\n" << std::endl;
	}
	else if (this->_hitPoint <= 0)
		std::cout <<  this->_name << " doesn't have any hit points left.\n" << std::endl;
	else
		std::cout << "Not enough energy point(s) to attack.\n" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint > amount)
	{
		this->_hitPoint -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages." << std::endl;
		std::cout << this->_name << " has " << this->_hitPoint << " hit points left.\n" << std::endl;
	}
	else if (this->_hitPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " does not have any hit points left already.\n" << std::endl;
	}
	else
	{
		this->_hitPoint = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damages and dies!\n" << std::endl;	
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint--;
		this->_hitPoint += amount;
		std::cout << "ClapTrap " << this->_name << " got back " << amount << " hit point(s)!" << std::endl;
		std::cout << this->_name << " has " << this->_hitPoint << " hit points left.\n" << std::endl;
	}
	else if (this->_hitPoint <= 0)
		std::cout <<  "ClapTrap " << this->_name << " doesn't have any hit points left.\n" << std::endl;
	else
		std::cout << "Not enough energy points to repair.\n" << std::endl;
	return ;
}
