/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:27:46 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 15:35:07 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern {

	public:

		/* Constructors and destructor */
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		/* Assignment operator */
		Intern	&operator=(Intern const &rhs);

		/* Member functions */
		Form	*makeForm(std::string const &name, std::string const &target) const;

		/* Exceptions */
		class FormUnknownException : public std::exception {
			public:
				virtual const char *what() const throw();
		} ;

};

#endif
