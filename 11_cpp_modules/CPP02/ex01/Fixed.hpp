/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:46 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:39:33 by mservais         ###   ########.fr       */
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
		Fixed &operator=(Fixed const &rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

	private:

		int					_fixed;
		static int const	_nbBits;

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
