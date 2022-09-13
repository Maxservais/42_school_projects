/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:32:51 by mservais          #+#    #+#             */
/*   Updated: 2022/02/11 14:32:53 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	public:

		HumanA(std::string name, Weapon	&weapon);
		~HumanA(void);

		void	attack(void) const;

	private:

		std::string	_name;
		Weapon		&_weapon;

};

#endif
