/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:57:11 by mservais          #+#    #+#             */
/*   Updated: 2022/03/07 16:19:04 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <str>" << std::endl;
		return (EXIT_FAILURE);
	}
	else
	{
		try
		{
			Convert	convert(argv[1]);
			std::cout << convert;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
