/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservais <mservais@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:39:59 by mservais          #+#    #+#             */
/*   Updated: 2022/03/10 14:51:27 by mservais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Whatever.hpp"

class Test
{
	private:
		int	_a;
	public:
		Test(int a) : _a(a) { }
		~Test() {};
		bool	operator<(Test const &rhs) const { return (this->_a < rhs._a); }
		bool	operator>(Test const &rhs) const { return (this->_a > rhs._a); }
		int		getVal() const { return (this->_a); }
};

int	main(void)
{
	int		a = 21;
	int		b = 42;
	Test	test1(3);
	Test	test2(12);

	std::cout << "a before: " << a << std::endl;
	std::cout << "b before: " << b << std::endl;
	::swap<int>(a, b);
	std::cout << "a after: " << a << std::endl;
	std::cout << "b after: " << b << std::endl;

	std::cout << "max: " << ::max<int>(a, b) << std::endl;
	std::cout << "min: " << ::min<int>(a, b) << std::endl;
	
	std::cout << test1.getVal() << std::endl;
	::swap<Test>(test1, test2);
	std::cout << test1.getVal() << std::endl;
	std::cout << "min: " << ::min<Test>(test1, test2).getVal() << std::endl;
	std::cout << "max: " << ::max<Test>(test1, test2).getVal() << std::endl;

	return (0);
}