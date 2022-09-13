/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:24 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 10:29:33 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		/* Constructors and destructor */
		WrongCat(void);
		WrongCat(std::string name);
		WrongCat(WrongCat const &src);
		~WrongCat(void);

		/* Assignment operator */
		WrongCat	&operator=(WrongCat const &rhs);

		/* Member functions */
		void		makeSound(void) const;

};

#endif
