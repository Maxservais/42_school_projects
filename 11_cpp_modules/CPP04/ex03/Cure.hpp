/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:13:14 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:36:56 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {

	public:

		/* Constructors and destructor */
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		/* Assignment operator */
		Cure	&operator=(Cure const &rhs);

		/* Member functions */
		AMateria	*clone() const;
		void		use(ICharacter &target);


};

#endif
