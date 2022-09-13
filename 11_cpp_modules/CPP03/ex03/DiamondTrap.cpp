/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:16:44 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 17:58:29 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

/* Constructors and destructor */

DiamondTrap::DiamondTrap(void) : 
ClapTrap("N/A_clap_name"),
ScavTrap(),
FragTrap(),
_name("N/A")
{
	this->FragTrap::_hitPoint = 100;
	this->ScavTrap::_energyPoint = 50;
	this->FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : 
ClapTrap(name + "_clap_name"),
ScavTrap(),
FragTrap(),
_name(name)
{
	this->FragTrap::_hitPoint = 100;
	this->ScavTrap::_energyPoint = 50;
	this->FragTrap::_attackDamage = 30;
	std::cout << "Parameterized DiamondTrap constructor called for " << this->_name << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) :
ClapTrap(src),
ScavTrap(),
FragTrap()
{
	std::cout << "Copy DiamondTrap constructor called for " << src._name << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
	return ;
}

/* Assignment operator */

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	ScavTrap();
	FragTrap();
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return (*this);
}

/* Member functions */

void DiamondTrap::whoAmI() {
	std::cout << "My name is '" << this->_name << "' and my ClapTrap name is '" << this->ClapTrap::_name << "'" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
	return ;
}
