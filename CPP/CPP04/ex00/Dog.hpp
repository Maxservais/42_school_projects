/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:44 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:21:49 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog : public Animal {

	public:

		/* Constructors and destructor */
		Dog(void);
		Dog(std::string name);
		Dog(Dog const &src);
		~Dog(void);

		/* Assignment operator */
		Dog		&operator=(Dog const &rhs);

		/* Member functions */
		void	makeSound(void) const;

};

#endif
