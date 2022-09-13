/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:25:54 by mservais          #+#    #+#             */
/*   Updated: 2022/03/02 16:46:18 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:

		/* Constructors and destructor */
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);

		/* Assignment operator */
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		/* Member functions */
		void	handle(Bureaucrat const &executor) const;

	private:

		PresidentialPardonForm(void);

} ;

#endif
