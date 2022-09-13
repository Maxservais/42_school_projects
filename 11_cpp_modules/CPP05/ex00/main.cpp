/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:28:34 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 10:29:08 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "-----Instantiation-----\n" << std::endl;
	Bureaucrat	bureaucrat1;
	Bureaucrat	bureaucrat2("John", 1);
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	try
	{
		/* Incrementing / decrementing */
		std::cout << "\n-----In/Decrement-----\n" << std::endl;
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;

		/* Wrong instantiation */
		// Bureaucrat	bureaucrat3("Maxime", 0);
		// Bureaucrat	bureaucrat4("Maxime", 151);
		// std::cout << "\n-----Wrong in/decrement-----\n" << std::endl;
		// bureaucrat1.decrementGrade();
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
