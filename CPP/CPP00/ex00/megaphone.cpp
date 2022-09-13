/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:22:28 by mservais          #+#    #+#             */
/*   Updated: 2022/02/10 13:21:08 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	char	ch;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			i = 0;
			len = strlen(*argv);
			while (i < len)
			{
				ch = toupper((*argv)[i]);
				std::cout << ch;
				i++;
			}
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
