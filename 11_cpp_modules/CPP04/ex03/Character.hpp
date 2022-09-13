/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:13:05 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 11:42:09 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {

	public:

		/* Constructors and destructor */
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		/* Assignment operator */
		Character			&operator=(Character const &rhs);

		/* Member functions */
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		/* Getter */
		std::string const	&getName() const;

	protected:

		std::string	_name;
		AMateria	*_inventory[4];

};

#endif
