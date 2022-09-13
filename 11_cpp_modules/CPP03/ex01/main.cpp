/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:07:42 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 12:09:56 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	maxime("Maxime");
	ScavTrap	clem("Clem");
	ScavTrap	josh;
	ScavTrap	emilie(clem);

	maxime.attack("Voldemort");
	maxime.takeDamage(5);
	maxime.beRepaired(10);
	maxime.takeDamage(15);
	clem.attack("Lisa");
	clem.takeDamage(99);
	clem.beRepaired(50);
	josh.guardGate();
	emilie.attack("Trump");
	emilie.guardGate();
	emilie.takeDamage(112);
	emilie.takeDamage(2);

	return (0);
}
