/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:32:12 by mservais          #+#    #+#             */
/*   Updated: 2022/03/16 14:05:11 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <numeric>
#include "Span.hpp"

/* Constructors and destructor */
Span::Span(unsigned int N) : _size(N) {}

Span::Span(Span const &other) : _size(other._size), _vec(other._vec) {}

Span::~Span() {}

/* Assignment operator */
Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_vec = rhs._vec;
	}
	return (*this);
}

/* Member functions */
void	Span::addNumber(int nbr)
{
	if (this->_vec.size() >= _size)
		throw(OutOfBoundariesException());
	else
		this->_vec.push_back(nbr);
}

void	Span::addNumber(std::vector<int>::iterator const &start, std::vector<int>::iterator const &end)
{
	int	dist = std::distance(start, end);
	if (dist + this->_vec.size() > _size)
	{
		this->_vec.insert(this->_vec.end(), start, start + (this->_size - this->_vec.size()));
		throw(OutOfBoundariesException());
	}
	else
	{
		this->_vec.insert(this->_vec.end(), start, end);
	}
}

int	Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw(NoSpanException());
	else
	{
		std::vector<int>	temp;

		std::copy(this->_vec.begin(), this->_vec.end(), std::back_inserter(temp));
		std::sort(temp.begin(), temp.end());
		std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
		return (std::abs(*std::min_element(temp.begin() + 1, temp.end())));
	}
}

int	Span::longestSpan()
{
	if (this->_vec.size() <= 1)
		throw(NoSpanException());
	else
		return (*std::max_element(this->_vec.begin(), this->_vec.end()) - *std::min_element(this->_vec.begin(), this->_vec.end()));
}

/* Exception */
const char *Span::OutOfBoundariesException::what() const throw()
{
	return ("Out of bound!");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Impossible to find out distance!");
}
