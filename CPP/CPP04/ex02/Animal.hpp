/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:49 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:04:17 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class AAnimal {

	public:

		/* Constructors and destructor */
		AAnimal(void);
		AAnimal(std::string name);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);

		/* Assignment operator */
		AAnimal			&operator=(AAnimal const &rhs);

		/* Member functions */
		virtual void	makeSound(void) const = 0;

		/* Getter */
		std::string		getType(void) const;

	protected:

		std::string		type;

};

#endif
