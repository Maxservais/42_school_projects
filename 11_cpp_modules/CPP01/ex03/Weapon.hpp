/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:33:04 by mservais          #+#    #+#             */
/*   Updated: 2022/02/11 13:49:31 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

	public:

		Weapon(std::string type);
		~Weapon(void);

		std::string	const &getType(void) const;
		void		setType(std::string new_type);

	private:

		std::string _type;

} ;

#endif
