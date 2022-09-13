/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:34:19 by mservais          #+#    #+#             */
/*   Updated: 2022/02/14 10:54:28 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen	karen1;

	std::cout << "DEBUG: ";
	karen1.complain("DEBUG");
	std::cout << "ERROR: ";
	karen1.complain("ERROR");
	std::cout << "WARNING: ";
	karen1.complain("WARNING");
	std::cout << "INFO: ";
	karen1.complain("INFO");
	return (0);	
}