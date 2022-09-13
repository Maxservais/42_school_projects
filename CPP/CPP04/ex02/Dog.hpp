/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:13 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:05:56 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	public:

		/* Constructors and destructor */
		Dog(void);
		Dog(std::string name);
		Dog(Dog const &src);
		~Dog(void);

		/* Assignment operator */
		Dog				&operator=(Dog const &rhs);

		/* Getter */
		Brain			*getBrain(void) const;

		/* Member functions */
		virtual void	makeSound(void) const;

	private:

		Brain	*_brain;

};

#endif
