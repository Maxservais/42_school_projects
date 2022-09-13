/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:28:34 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 16:36:04 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "-----Instantiation-----\n" << std::endl;
	Bureaucrat	bureaucrat1("John", 6);
	Bureaucrat	bureaucrat2("Marc", 25);
	Bureaucrat	bureaucrat3("Brian", 145);
	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << bureaucrat3 << "\n" << std::endl;

	std::cout << "\n-----Presidential Pardon-----\n\n" << std::endl;
	PresidentialPardonForm	form1("evil man");
	PresidentialPardonForm	form2("good looking guy");
	std::cout << form1 << std::endl;
	std::cout << form2 << "\n\n" << std::endl;

	std::cout << "--bureaucrat1.signForm(form1)--" << std::endl;
	bureaucrat1.signForm(form1);
	std::cout << "\n--bureaucrat2.signForm(form1)--" << std::endl;
	bureaucrat2.signForm(form1);
	std::cout << "\n--bureaucrat2.signForm(form2)--" << std::endl;
	bureaucrat2.signForm(form2);
	std::cout << "\n--bureaucrat2.executeForm(form1)--" << std::endl;
	bureaucrat2.executeForm(form1);
	std::cout << "\n--bureaucrat2.executeForm(form2)--" << std::endl;
	bureaucrat2.executeForm(form2);
	std::cout << "\n--bureaucrat1.executeForm(form2)--" << std::endl;
	bureaucrat1.executeForm(form2);
	std::cout << "\n--bureaucrat1.signForm(form2)--" << std::endl;
	bureaucrat1.signForm(form2);
	std::cout << "\n--bureaucrat1.executeForm(form2)--" << std::endl;
	bureaucrat1.incrementGrade();
	bureaucrat1.executeForm(form2);

	std::cout << "\n\n-----RobotomyRequestForm-----\n\n" << std::endl;
	srand(time(NULL));
	RobotomyRequestForm	form3("your cousin");
	RobotomyRequestForm	form4("your mama");
	std::cout << form3 << std::endl;
	std::cout << form4 << "\n\n" << std::endl;

	std::cout << "--bureaucrat1.signForm(form3)--" << std::endl;
	bureaucrat1.signForm(form3);
	std::cout << "\n--bureaucrat2.signForm(form3)--" << std::endl;
	bureaucrat2.signForm(form3);
	std::cout << "\n--bureaucrat3.signForm(form4)--" << std::endl;
	bureaucrat3.signForm(form4);
	std::cout << "\n--bureaucrat2.signForm(form4)--" << std::endl;
	bureaucrat2.signForm(form4);
	std::cout << "\n--bureaucrat2.executeForm(form3)--" << std::endl;
	bureaucrat2.executeForm(form3);
	std::cout << "\n--bureaucrat2.executeForm(form4)--" << std::endl;
	bureaucrat2.executeForm(form4);
	std::cout << "\n--bureaucrat1.executeForm(form4)--" << std::endl;
	bureaucrat1.executeForm(form4);
	std::cout << "\n--bureaucrat1.signForm(form4)--" << std::endl;
	bureaucrat1.signForm(form4);
	std::cout << "\n--bureaucrat1.executeForm(form4)--" << std::endl;
	bureaucrat1.executeForm(form4);

	
	std::cout << "\n\n-----ShrubberyCreationForm-----\n" << std::endl;
	ShrubberyCreationForm	form5("your cousin");
	ShrubberyCreationForm	form6("your mama");
	std::cout << form5 << std::endl;
	std::cout << form6 << "\n\n" << std::endl;

	std::cout << "--bureaucrat3.decrementGrade()--" << std::endl;
	bureaucrat3.decrementGrade();
	std::cout << "--bureaucrat1.signForm(form5)--" << std::endl;
	bureaucrat3.signForm(form5);
	std::cout << "\n--bureaucrat2.signForm(form5)--" << std::endl;
	bureaucrat2.signForm(form5);
	std::cout << "\n--bureaucrat2.signForm(form5)--" << std::endl;
	bureaucrat2.signForm(form5);
	std::cout << "\n--bureaucrat2.executeForm(form5)--" << std::endl;
	bureaucrat2.executeForm(form5);
	std::cout << "--bureaucrat1.signForm(form5)--" << std::endl;
	std::cout << "--bureaucrat3.incrementGrade()--" << std::endl;
	bureaucrat3.incrementGrade();
	std::cout << "--bureaucrat3.signForm(form6)--" << std::endl;
	bureaucrat3.signForm(form6);
	std::cout << "\n--bureaucrat2.executeForm(form6)--" << std::endl;
	bureaucrat2.executeForm(form6);

	return (0);
}
