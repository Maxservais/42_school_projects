/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:44:52 by mservais          #+#    #+#             */
/*   Updated: 2022/03/14 12:45:00 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
	public:

		/* Default constructor */
		Array<T>()
		{
			this->_size = 0;
			this->_arr = new T[0];
			return ;
		};

		/* Parameterized constructor */
		Array<T>(unsigned int n) : _size(n), _arr(new T[n])
		{
			return ;
		}
 
		/* Copy constructor */
		Array<T>(Array<T> const &src)
		{
			this->_size = src._size;
			this->_arr = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
				this->_arr[i] = src._arr[i];
			return ;
		}

		/* Destructor */
		~Array<T>(void)
		{
			delete [] this->_arr;
		}

		/* Assignment operator */
		Array<T> &operator=(Array<T> const &rhs)
		{
			if (this != &rhs)
			{
				this->~Array();
				this->_size = rhs._size;
				this->_arr = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					this->_arr[i] = rhs._arr[i];
			}
			return (*this);
		}

		/* Overload operator [] */
		T	&operator[](unsigned int index)
		{
			// if (index < 0 || index >= this->_size)
			// 	throw(std::exception());
			// else
			// 	return (this->_arr[index]);
			if (index >= 0 && index < this->_size)
				return (this->_arr[index]);
			else
				throw(std::exception());
		}

		/* Member function */
		unsigned int	size() const
		{
			return (this->_size);
		}

	private:

		unsigned int	_size;
		T		*_arr;

};


#endif
