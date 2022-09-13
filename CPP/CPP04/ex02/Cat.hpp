/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:00 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:20 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	public:

		/* Constructors and destructor */
		Cat(void);
		Cat(std::string name);
		Cat(Cat const &src);
		~Cat(void);

		/* Assignment operator */
		Cat				&operator=(Cat const &rhs);

		/* Getter */
		Brain			*getBrain(void) const;

		/* Member functions */
		virtual void	makeSound(void) const;

	private:

		Brain	*_brain;

};

#endif
