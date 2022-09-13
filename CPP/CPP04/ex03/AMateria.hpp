/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:07:43 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:35:11 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {

	public:

		/* Constructors and destructor */
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);

		/* Assignment operator */
		AMateria	&operator=(AMateria const &rhs);

		/* Member functions */
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);

		/* Getter */
		std::string const & getType() const;

	protected:

		std::string	_type;

};

#endif
