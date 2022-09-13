/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:07:42 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 18:01:02 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int	main(void)
{
	// ClapTrap	maxime("Maxime");
	// ScavTrap	clem("Clem");
	// FragTrap	michael("Michael");
	DiamondTrap	emilie("Emilie");
	// DiamondTrap	john;

	// std::cout << "\n-----------------------------------\n" << std::endl;
	
	// maxime.attack("Voldemort");
	// maxime.takeDamage(5);
	// maxime.beRepaired(10);
	// maxime.takeDamage(15);
	
	// std::cout << "-----------------------------------\n" << std::endl;
	
	// clem.attack("Mona");
	// clem.takeDamage(99);
	// clem.beRepaired(50);
	
	// std::cout << "-----------------------------------\n" << std::endl;
	
	// michael.attack("Lisa");
	// michael.highFivesGuys();
	
	std::cout << "-----------------------------------\n" << std::endl;	

	emilie.whoAmI();
	emilie.attack("John");
	emilie.highFivesGuys();
	emilie.takeDamage(32);
	emilie.beRepaired(10);
	
	std::cout << "-----------------------------------\n" << std::endl;	

	return (0);
}
