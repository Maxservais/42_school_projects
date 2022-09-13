/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:05:28 by mservais          #+#    #+#             */
/*   Updated: 2022/02/25 12:21:45 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {

	public:

		/* Constructors and destructor */
		Cat(void);
		Cat(std::string name);
		Cat(Cat const &src);
		~Cat(void);

		/* Assignment operator */
		Cat		&operator=(Cat const &rhs);

		/* Member functions */
		void	makeSound(void) const;

};

#endif
