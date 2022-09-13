/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:42:47 by mservais          #+#    #+#             */
/*   Updated: 2022/03/07 14:07:14 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Convert {
	
	public:

		/* Constructors and destructor */
		Convert(std::string const &value);
		Convert(Convert const &src);
		~Convert();
		
		/* Assignment operator */
		Convert	&operator=(Convert const &rhs);

		/* Member functions */
		char	convertToChar() const;
		int		convertToInt() const;
		float	convertToFloat() const;
		double	convertToDouble() const;

		/* Exceptions */
		class ImpossibleToDisplayException : public std::exception {
			public:
				virtual const char	*what() const throw();
		} ;

		class ImpossibleToConvertException : public std::exception {
			public:
				virtual const char	*what() const throw();
		} ;

	private:
		Convert();
		int			_i;
		char		_c;
		float		_f;
		double		_d;
		int			_type;
		std::string	_argv;

} ;

std::ostream &operator<<(std::ostream &o, Convert const &i);

#endif
