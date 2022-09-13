/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:28:34 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 10:46:54 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "-----Instantiation-----\n" << std::endl;
	Bureaucrat	bureaucrat1("John", 1);
	Bureaucrat	bureaucrat2("Marc", 150);
	std::cout << bureaucrat1 << "\n "<< std::endl;
	std::cout << bureaucrat2 << "\n "<< std::endl;

	Form		form1;
	Form		form2("important paper", 110, 5);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	
	bureaucrat1.signForm(form1);
	std::cout << std::endl;
	
	try
	{
		/* Wrong instantiation */
		// Form	form3("paper", 151, 1);
		// Form	form4("important doc", 150, 0);

		/* Unable to sign form */
		// bureaucrat2.signForm(form1);
		// bureaucrat2.signForm(form2);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}