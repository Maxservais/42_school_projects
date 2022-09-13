/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:26:01 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 14:26:16 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

/* Constructors and destructor */

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery Creation Form", 145, 137, target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

/* Assignment operator */

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	Form::operator=(rhs);
	return (*this);
}

/* Member functions */

void	ShrubberyCreationForm::handle(Bureaucrat const &executor) const {
	this->Form::execute(executor);
	std::ofstream	ofs;
	ofs.open(this->getTarget() + "_shrubbery");
	if (ofs.is_open() == true)
	{
		ofs << "    /\\" << std::endl;
		ofs << "   /  \\" << std::endl;
		ofs << "   /~~\\o" << std::endl;
		ofs << "  /o   \\" << std::endl;
		ofs << " /~~*~~~\\" << std::endl;
		ofs << " o/    o \\" << std::endl;
		ofs << " /~~~~~~~~\\~" << std::endl; 
		ofs << "/__*_______\\" << std::endl; 
		ofs << "     ||" << std::endl; 
		ofs <<"   \\====/" << std::endl;
		ofs <<"    \\__/" << std::endl; 
	}
	else
		std::cerr << "Error opening file" << std::endl;
	ofs.close();
	return ;
}