/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:37:49 by mservais          #+#    #+#             */
/*   Updated: 2022/03/10 10:59:19 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors and destructor */

Form::Form(void) :
_name("undefined_form"),
_signed(false),
_gradeSign(150),
_gradeExecute(150)
{
	return ;
}

Form::Form(std::string const &name, unsigned int const gradeSign, unsigned int const gradeExec) :
_name(name),
_signed(false),
_gradeSign(gradeSign),
_gradeExecute(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(Form const &src) :
_name(src._name),
_signed(src._signed),
_gradeSign(src._gradeSign),
_gradeExecute(src._gradeExecute)
{
	return ;
}

Form::~Form(void) {
	return ;
}

/* Assignment operator */
Form	&Form::operator=(Form const &rhs) {
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/* Getters */

std::string const	&Form::getName() const {
	return (this->_name);
}

unsigned int	Form::getGradeSign() const {
	return (this->_gradeSign);
}

unsigned int	Form::getGradeExecute() const {
	return (this->_gradeExecute);
}

bool	Form::getStatus() const {
	return (this->_signed);
}

/* Member functions */

void	Form::beSigned(Bureaucrat const &other) {
	if (this->_signed == true)
		throw Form::FormSignedAlreadyException();
	else if (other.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

/* Exceptions */
const char	*Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char	*Form::FormSignedAlreadyException::what() const throw() {
	return ("Form has already been signed!");
}

/* Insertion operator */

std::ostream	&operator<<(std::ostream &o, Form const &i) {
	o << "Form name: \"" << i.getName() << "\"" << std::endl;
	o << "Signed? " << i.getStatus() << "\tGrade required to sign? " << i.getGradeSign() << "\tGrade required to execute? "	<< i.getGradeExecute() << std::endl;
	return (o);
}
