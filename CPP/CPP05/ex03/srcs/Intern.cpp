/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:27:43 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 16:43:00 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* Constructors and destructor */

Intern::Intern(void) {
	return ;
}

Intern::Intern(Intern const &src) {
	(void)src;
	return ;
}

Intern::~Intern(void) {
	return ;
}

/* Assignment operator */

Intern	&Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return (*this);
}

/* Member functions */

Form	*Intern::makeForm(std::string const &name, std::string const &target) const {
	enum Forms
	{
		presidentialPardonForm,
		robotomyRequestForm,
		shrubberyCreationForm
	};
	std::string	form_names[3] = {
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation Form"
		};
	int i;
	for (i = 0; i < 3; i++)
	{
		if (name == form_names[i])
			break ;
	}
	Form	*form;
	switch (i) {
		case presidentialPardonForm:
			form = new PresidentialPardonForm(target);
			break ;
		case robotomyRequestForm:
			form = new RobotomyRequestForm(target);
			break ;
		case shrubberyCreationForm:
			form = new ShrubberyCreationForm(target);
			break ;
		default:
			throw Intern::FormUnknownException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}

/* Exceptions */

const char	*Intern::FormUnknownException::what() const throw() {
	return ("Intern could not create form!");
}
