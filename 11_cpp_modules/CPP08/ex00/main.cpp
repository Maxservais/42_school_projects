/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:35:06 by mservais          #+#    #+#             */
/*   Updated: 2022/03/15 12:05:08 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Easyfind.hpp"

void	print(int nbr)
{
	std::cout << nbr << std::endl;
}

int	main(void)
{
	/* TEST 1 */
	{
		size_t						size = 5;
		std::vector<int>			v(size);
		
		/* Fill vector */
		for (size_t i = 0; i < size; i++)
				v[i] = (i + 1) * 3;

		/* Print vector's content */
		std::for_each(v.begin(), v.end(), print);

		/* Call easyfind() */
		try
		{
			easyfind(v, 15);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	/* TEST 2 */
	{
		int	arr[4] = {2, 4, 4, 2};

		/* Fill list */
		std::list<int>	l(arr, std::end(arr));

		/* Call easyfind() */
		try
		{
			easyfind(l, 15);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
