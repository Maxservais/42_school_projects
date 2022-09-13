/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:00:17 by mservais          #+#    #+#             */
/*   Updated: 2022/02/11 11:05:52 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(10, "zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
