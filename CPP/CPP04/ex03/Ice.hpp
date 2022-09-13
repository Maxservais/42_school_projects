/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:13:09 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:37:01 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {

	public:

		/* Constructors and destructor */
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);

		/* Assignment operator */
		Ice	&operator=(Ice const &rhs);

		/* Member functions */
		AMateria	*clone() const;
		void		use(ICharacter &target);

};

#endif
