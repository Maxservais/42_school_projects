/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:55:12 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 17:24:06 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " died!" << std::endl;
	return ;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
