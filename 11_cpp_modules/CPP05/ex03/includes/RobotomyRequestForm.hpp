/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:25:59 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 13:31:18 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {

	public:

		/* Constructors and destructor */
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		/* Assignment operator */
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		/* Member functions */
		void	handle(Bureaucrat const &executor) const;

	private:

		RobotomyRequestForm(void);

} ;

#endif