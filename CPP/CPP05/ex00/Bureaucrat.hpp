/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:29:26 by mservais          #+#    #+#             */
/*   Updated: 2022/03/03 10:22:48 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

class Bureaucrat {

	public:

		/* Constructors and destructor */
		Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		/* Assignment operator */
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		/* Getters */
		unsigned int		getGrade() const;
		std::string const	&getName() const;

		/* Member functions */
		void	incrementGrade();
		void	decrementGrade();

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string const	_name;
		unsigned int		_grade;

};

/* Insertion operator */
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif
