/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:00:17 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 17:34:34 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie1("Brad");
	Zombie	*zombie2 = newZombie("Pamela");
	zombie1.announce();
	zombie2->announce();
	randomChump("Marc");
	delete zombie2;
	return (0);
}
