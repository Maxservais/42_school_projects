/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:11:06 by mservais          #+#    #+#             */
/*   Updated: 2022/03/16 13:55:35 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		/* Iterators */
		typedef typename MutantStack::stack::container_type::iterator			iterator;
		typedef typename MutantStack::stack::container_type::reverse_iterator reverse_iterator;
		
		/* Constructors and destructor */
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		virtual ~MutantStack() {}

		/* Assignment operator */
		MutantStack &operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
				this->operator=(rhs);
			return (*this);
		}
		
		/* Member functions */
		iterator			begin() { return this->c.begin(); }
		iterator			end() { return this->c.end(); }
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }

} ;

#endif
