/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:49 by mservais          #+#    #+#             */
/*   Updated: 2022/02/21 16:06:51 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

	public:

		/* Constructors and destructor */
		Animal(void);
		Animal(std::string name);
		Animal(Animal const &src);
		virtual ~Animal(void);

		/* Assignment operator */
		Animal			&operator=(Animal const &rhs);

		/* Member functions */
		virtual void	makeSound(void) const;

		/* Getter */
		std::string		getType(void) const;

	protected:

		std::string		type;

};

#endif
