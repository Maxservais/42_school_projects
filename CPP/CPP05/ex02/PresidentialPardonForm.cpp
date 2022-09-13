/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:25:51 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 12:24:19 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

/* Constructors and destructor */

PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("Presidential Pardon", 25, 5, target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

/* Assignment operator */

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	Form::operator=(rhs);
	return (*this);
}

/* Member functions */

void	PresidentialPardonForm::handle(Bureaucrat const &executor) const {
	this->Form::execute(executor);
	std::cout << "\"" << this->Form::getTarget() << "\"" << " was pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}
