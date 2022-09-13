/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:34:19 by mservais          #+#    #+#             */
/*   Updated: 2022/02/14 18:15:01 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

enum levels {
	DEBUG,
	INFO,
	WARNING,
	ERROR	
};

int	getInput(std::string str)
{
	std::string	level[4] = {
		"DEBUG",
		"INFO",
		"WARNING", 
		"ERROR"
		};
	for (int i = 0; i < 4; i++)
	{
		if (str == level[i])
			return i;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Karen	karen;
	int		res;

	if (argc != 2)
	{
		std::cout << "Usage: ./karenFilter \"LEVEL\"" << std::endl;
		return (1);
	}
	else
	{
		res = getInput(std::string(argv[1]));
		switch (res)
		{
			case DEBUG :
				std::cout << "[ DEBUG ]" << std::endl;
				karen.complain("DEBUG");
			case INFO :
				std::cout << "[ INFO ]" << std::endl;
				karen.complain("INFO");
			case WARNING :
				std::cout << "[ WARNING ]" << std::endl;
				karen.complain("WARNING");
			case ERROR :
				std::cout << "[ ERROR ]" << std::endl;
				karen.complain("ERROR");
				break ;
			default :
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return (0);
}