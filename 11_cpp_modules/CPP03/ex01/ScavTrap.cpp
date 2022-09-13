/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:43 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 12:21:51 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/* Constructors and destructor */

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap derived default constructor called" << std::endl;
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap parameterized derived constructor called for " << this->_name << std::endl;
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "ScavTrap derived copy constructor called\n" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap derived destructor called for " << this->_name << std::endl;
	return ;
}

/* Assignment operator */

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "ScavTrap derived copy assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return (*this);
}

/* Member functions */

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoint > 0 && this->_energyPoint > 0)
	{
		this->_energyPoint--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << this->_name << " has " << this->_energyPoint << " energy points left.\n" << std::endl;
	}
	else if (this->_hitPoint <= 0)
		std::cout <<  this->_name << " doesn't have any hit points left.\n" << std::endl;
	else
		std::cout << "Not enough energy point(s) to attack.\n" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode\n" << std::endl;
	return ;
}
