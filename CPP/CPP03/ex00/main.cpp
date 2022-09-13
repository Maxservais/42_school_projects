/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:07:42 by mservais          #+#    #+#             */
/*   Updated: 2022/02/17 15:31:52 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	alice("Alice");

	std::cout << std::endl;
	bob.attack("Alice");
	alice.attack("Bob");
	bob.attack("John");
	bob.takeDamage(6);
	bob.beRepaired(3);

	return (0);
}
