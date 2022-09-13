/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:06:49 by mservais          #+#    #+#             */
/*   Updated: 2022/02/22 14:06:34 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

	public:

		/* Constructors and destructor */
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);

		/* Assignment operator */
		Brain			&operator=(Brain const &rhs);

		/* Getter */
		std::string		getIdeas(int i) const;

	private:

		std::string		_ideas[100];

};

#endif
