/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:34:19 by mservais          #+#    #+#             */
/*   Updated: 2022/02/14 10:17:58 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdio.h>

int	check_usage(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [filename] [str1] [str2]" << std::endl;
		return (1);
	}
	if (!strcmp(argv[2], "") || !strcmp(argv[3], ""))
	{
		std::cout << "str1 and str2 CANNOT be empty!" << std::endl;
		return (1);
	}
	return (0);
}

std::string	toupper(std::string str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	if (check_usage(argc, argv))
		return (1);
	else
	{
		std::ifstream		ifs(argv[1]);
		if (ifs.fail())
		{
			std::cout << "Something went wrong when trying to open the file specified" << std::endl;
			return (1);
		}
		else if (ifs.peek() == std::ifstream::traits_type::eof())
		{
			std::cout << "Input file is empty." << std::endl;
			return (1);
		}
		else
		{
			std::string			str_before;
			std::string			str1 = argv[2];
			std::string			str2 = argv[3];
			std::stringstream	buffer;
			size_t				pos;
			std::ofstream		ofs(toupper(std::string(argv[1])).append(".replace").c_str());
			if (ofs.fail())
			{
				std::cout << "Something went wrong when trying to open a new file" << std::endl;
				return (1);
			}
			buffer << ifs.rdbuf();
			ifs.close();
			str_before = buffer.str();
			while ((pos = str_before.find(str1)) != std::string::npos)
			{
				str_before.erase(pos, str1.length());
				str_before.insert(pos, str2);
			}
			ofs << str_before;
			ofs.close();
			return (0);	
		}
	}
}