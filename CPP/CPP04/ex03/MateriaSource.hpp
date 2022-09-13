/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:24:39 by mservais          #+#    #+#             */
/*   Updated: 2022/02/23 19:33:17 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public:

		/* Constructors and destructor */
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);

		/* Assignment operator */
		MateriaSource	&operator=(MateriaSource const &rhs);

		/* Member functions */
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	private:

		AMateria	*_inventory[4];

};

#endif


