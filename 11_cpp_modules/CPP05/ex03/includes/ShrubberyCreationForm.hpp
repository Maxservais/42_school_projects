/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:26:03 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 13:38:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {

	public:

		/* Constructors and destructor */
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);

		/* Assignment operator */
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		/* Member functions */
		void	handle(Bureaucrat const &executor) const;

	private:

		ShrubberyCreationForm(void);

} ;

#endif