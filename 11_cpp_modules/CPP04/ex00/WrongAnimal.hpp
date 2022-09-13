/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:15 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 10:29:20 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {

	public:

		/* Constructors and destructor */
		WrongAnimal(void);
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);

		/* Assignment operator */
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		/* Member functions */
		void		makeSound(void) const;

		/* Getter */
		std::string	getType(void) const;

	protected:

		std::string		type;

};

#endif
