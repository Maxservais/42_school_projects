/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:32:55 by mservais          #+#    #+#             */
/*   Updated: 2022/02/18 16:37:35 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:

		/* Constructors and destructor */
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);

		/* Assignment operator */
		ScavTrap	&operator=(ScavTrap const &rhs);

		/* Member functions */
		void	guardGate(void);
		void	attack(const std::string& target);

};

#endif
