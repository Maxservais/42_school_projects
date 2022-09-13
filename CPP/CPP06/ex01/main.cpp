/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:57:11 by mservais          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:03 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int	main(void)
{
	Data	test;

	test.name = "coucou";

	std::cout << "name: " << test.name << std::endl;
	std::cout << "address: " << &test << std::endl;
	std::cout << "address: " << deserialize(serialize(&test)) << std::endl;

	uintptr_t	value = serialize(&test);
	Data		*output = deserialize(value);
	std::cout << "name: " << output->name << std::endl;
	std::cout << "address: " << output << std::endl;

	return (EXIT_SUCCESS);
}
