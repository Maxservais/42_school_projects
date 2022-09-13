/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:36:36 by mservais          #+#    #+#             */
/*   Updated: 2022/02/14 15:38:47 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>

class Karen {
	
	public:

		Karen(void);
		~Karen(void);
		void	complain(std::string level);

	private:

		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
} ;

#endif
