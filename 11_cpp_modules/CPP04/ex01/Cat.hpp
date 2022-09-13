/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:00 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:24:51 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

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
		void	makeSound(void) const;

	private:

		Brain	*_brain;

};

#endif
