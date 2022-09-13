/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:42:40 by mservais          #+#    #+#             */
/*   Updated: 2022/03/07 17:31:36 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits>
#include "Convert.hpp"

/* Macros */

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

/* Constructors and destructor */

Convert::Convert() {}

Convert::Convert(std::string const &value) : _argv(value) {
	if (this->_argv.length() == 1)
	{
		if (isdigit(this->_argv[0]))
		{
			this->_i = static_cast<int>(strtol(this->_argv.c_str(), NULL, 10));
			this->_type = INT;
		}
		else
		{
			this->_c = this->_argv[0];
			this->_type = CHAR;
		}
	}
	else
	{
		char	*endptr;
		long	val;
		float	decimal_value;

		val = strtol(this->_argv.c_str(), &endptr, 10);
		if (!*endptr)
		{
			if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
				throw(Convert::ImpossibleToConvertException());
			else
			{
				this->_i = static_cast<int>(val);
				this->_type = INT;
			}
		}
		else
		{
			decimal_value = strtof(this->_argv.c_str(), &endptr);
			if (*endptr == 'f' && *(endptr + 1) == '\0')
			{
				this->_f = static_cast<float>(decimal_value);
				this->_type = FLOAT;
			}
			else if (!*endptr)
			{
				this->_d = static_cast<double>(decimal_value);
				this->_type = DOUBLE;
			}
			else
				throw(Convert::ImpossibleToConvertException());
		}
	}
	return ;
}

Convert::Convert(Convert const &src) {
	_argv = src._argv;
	return ;
}

Convert::~Convert() {}

/* Assignment operator */

Convert	&Convert::operator=(Convert const &rhs) {
	if (this != &rhs)
	{
		this->_i = rhs._i;
		this->_c = rhs._c;
		this->_f = rhs._f;
		this->_d = rhs._d;
	}
	return (*this);
}

/* Member functions */
char	Convert::convertToChar() const {

	switch (this->_type) {
		char	character;
		case CHAR:
			return (this->_c);
		case INT:
			character = static_cast<char>(this->_i);
			if (!isprint(character))
				throw(Convert::ImpossibleToDisplayException());
			else
				return (character);
		case FLOAT:
			if (isinf(this->_f) || isnan(this->_f) || this->_f > std::numeric_limits<char>::max() || this->_f < std::numeric_limits<char>::min())
				throw(Convert::ImpossibleToConvertException());
			else if (!isprint(static_cast<char>(this->_f)))
				throw(Convert::ImpossibleToDisplayException());
			else
				return (static_cast<char>(this->_f));
		case DOUBLE:
			if (isinf(this->_d) || isnan(this->_d) || this->_d > std::numeric_limits<char>::max() || this->_d < std::numeric_limits<char>::min())
				throw(Convert::ImpossibleToConvertException());
			else if (!isprint(static_cast<char>(this->_d)))
				throw(Convert::ImpossibleToDisplayException());
			else
				return (static_cast<char>(this->_d));
	}
	return (this->_c);
}

int		Convert::convertToInt() const {
	switch (this->_type) {
		case CHAR:
			return (static_cast<int>(this->_c));
		case INT:
			return (this->_i);
		case FLOAT:
			if (isinf(this->_f) || isnan(this->_f) || (intmax_t)this->_f > (intmax_t)std::numeric_limits<int>::max() || (intmax_t)this->_f < (intmax_t)std::numeric_limits<int>::min())
				throw(Convert::ImpossibleToConvertException());
			else
				return (static_cast<int>(this->_f));
		case DOUBLE:
			if (isinf(this->_d) || isnan(this->_d) || (intmax_t)this->_d > (intmax_t)std::numeric_limits<int>::max() || (intmax_t)this->_d < (intmax_t)std::numeric_limits<int>::min())
				throw(Convert::ImpossibleToConvertException());
			else
				return (static_cast<int>(this->_d));
	}
	return (this->_i);
}

float	Convert::convertToFloat() const {
	switch (this->_type) {
		case CHAR:
			return (static_cast<float>(this->_c));
		case INT:
			return (static_cast<float>(this->_i));
		case FLOAT:
			return (this->_f);
		case DOUBLE:
			return (static_cast<float>(this->_d));
	}
	return (this->_f);
}

double	Convert::convertToDouble() const {
	switch (this->_type) {
		case CHAR:
			return (static_cast<double>(this->_c));
		case INT:
			return (static_cast<double>(this->_i));
		case FLOAT:
			return (static_cast<double>(this->_f));
		case DOUBLE:
			return (this->_d);
	}
	return (this->_d);
}

/* Exceptions */

const char	*Convert::ImpossibleToDisplayException::what() const throw() {
	return ("Non displayable");
}

const char	*Convert::ImpossibleToConvertException::what() const throw() {
	return ("Impossible");
}


/* Insertion operator */

std::ostream &operator<<(std::ostream &o, Convert const &i) {
	try {
		o << "char: " << i.convertToChar() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		o << "int: " << i.convertToInt() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		o << "float: " << std::fixed << std::setprecision(1) << i.convertToFloat() << "f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		o << "double: " << std::setprecision(1) << i.convertToDouble() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (o);
}
