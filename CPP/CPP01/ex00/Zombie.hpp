/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:48:45 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 17:35:00 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	
	public:

		Zombie(std::string name);
		~Zombie(void);

		void	announce(void) const;

	private:

		std::string	_name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
