/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:17:27 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 14:25:03 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/* Constructors and destructor */

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap derived default constructor called" << std::endl;
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap parameterized derived constructor called for " << this->_name << std::endl;
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "FragTrap derived copy constructor called\n" << std::endl;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap derived destructor called for " << this->_name << std::endl;
	return ;
}

/* Assignment operator */

FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "FragTrap derived copy assignment operator called" << std::endl;
	ClapTrap::operator=(rhs);
	std::cout << "Name: " << this->_name << "\t Hit point(s): " << this->_hitPoint << "\t Energy point(s): " << this->_energyPoint << "\t Attack damage: " << this->_attackDamage << std::endl;
	return (*this);
}

/* Member functions */

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " would love to do a High Five with someone!\n" << std::endl;
	return ;
}
