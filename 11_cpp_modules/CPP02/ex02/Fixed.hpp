/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:44:56 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:39:30 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed(Fixed const &src);
		~Fixed(void);

		/* Assignment operator */
		Fixed	&operator=(Fixed const &rhs);

		/* Comparison operators (>,<,>=,<=,==,!=) */
		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);

		/* Arithmetic operators (+,-,*,/) */
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		/* Increment and decrement operators */
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		/* Public Member functions */
		int					toInt(void) const;
		float				toFloat(void) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		
		/* Getter and setter */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					_fixed;
		static int const	_nbBits;

};

/* Insertion operator */
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
