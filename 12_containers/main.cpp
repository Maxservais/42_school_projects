#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest/doctest.h"
#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./containers/map.hpp"
#include "./utils/binary_search_tree.hpp"
#include "./utils/binary_search_tree_iterator.hpp"
#include "./utils/utils.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

//////////////////////////////////////////////////
//												//
//					RBT							//
//												//
//////////////////////////////////////////////////


TEST_CASE("Red Black Tree") {
	ft::RedBlackTree<int, int> rbt;
	rbt.insert(ft::make_pair(2, 17));
	rbt.insert(ft::make_pair(-33, 17));
	rbt.insert(ft::make_pair(883, 17));
	rbt.insert(ft::make_pair(83, 17));
	rbt.insert(ft::make_pair(0, 17));
	rbt.insert(ft::make_pair(-1, 17));

	SUBCASE("insert & delete string:int)") {
		ft::RedBlackTree<std::string, int>	rbt;
		rbt.insert(ft::make_pair("a", 344));
		rbt.insert(ft::make_pair("b", 2222));
		rbt.insert(ft::make_pair("c", 111));
		rbt.insert(ft::make_pair("d", 2333));
		rbt.deleteNode("b");
		rbt.deleteNode("e");
	}
	SUBCASE("insert & delete int:string'") {
		ft::RedBlackTree<int, std::string>	rbt;
		rbt.insert(ft::make_pair(1, "s"));
		rbt.insert(ft::make_pair(2, "coucou"));
		rbt.insert(ft::make_pair(-123, "hey"));
		rbt.insert(ft::make_pair(-93, "eejje"));
		rbt.deleteNode(15);
		rbt.deleteNode(2);
	}
}


//////////////////////////////////////////////////
//												//
//					MAP							//
//												//
//////////////////////////////////////////////////

/*
|-----------------------------------------------|
|		1.1 CONSTRUCTORS						|
|-----------------------------------------------|
*/

TEST_CASE("Constructors, destructor and operator=") {

	/* Empty constructor */
	std::map<int, int>	std0;
	ft::map<int, int>	ft0;
	for (int i = 0; i < 42; ++i)
	{
		std0.insert(std::make_pair(i, i * 2 + 5));
		ft0.insert(ft::make_pair(i, i * 2 + 5));
	}

	CHECK(std0[2] == ft0[2]);
	CHECK(std0[-2] == ft0[-2]);
	CHECK(std0[40] == ft0[40]);
	CHECK(std0.size() == ft0.size());
	CHECK(std0.empty() == ft0.empty());
	
	/* Copy constructor */
	std::map<int, int>	std1 = std0;
	ft::map<int, int>	ft1 = ft0;

	CHECK(std1[2] == ft1[2]);
	CHECK(std1[-2] == ft1[-2]);
	CHECK(std1[40] == ft1[40]);
	CHECK(std1.size() == ft1.size());
	CHECK(std1.empty() == ft1.empty());

	/* Assignment operator */
	std::map<int, int>	std2;
	std2 = std0;
	ft::map<int, int>	ft2;
	ft2 = ft0;

	CHECK(std2[2] == ft2[2]);
	CHECK(std2[-2] == ft2[-2]);
	CHECK(std2[40] == ft2[40]);
	CHECK(std2.size() == ft2.size());
	CHECK(std2.empty() == ft2.empty());

	/* Range constructor */
	std::map<int, int>::iterator it_std0 = std0.begin();
	std::map<int, int>::iterator ite_std0 = std0.find(5);
	std::map<int, int>	std3(it_std0, ite_std0);

	ft::map<int, int>::iterator it_ft0 = ft0.begin();
	ft::map<int, int>::iterator ite_ft0 = ft0.find(5);
	ft::map<int, int>	ft3(it_ft0, ite_ft0);

	CHECK(std3[2] == ft3[2]);
	CHECK(std3[-2] == ft3[-2]);
	CHECK(std3[40] == ft3[40]);
	CHECK(std3.size() == ft3.size());
	CHECK(std3.empty() == ft3.empty());
}

TEST_CASE("Iterators") {
	std::map<int, int>	std0;
	ft::map<int, int>	ft0;
	for (int i = 0; i < 42; ++i)
	{
		std0.insert(std::make_pair(i, i * 2 + 5));
		ft0.insert(ft::make_pair(i, i * 2 + 5));
	}

	SUBCASE("bidirectional iterators") {
		/* begin() and end() */
		ft::map<int, int>::iterator it = ft0.begin();
		ft::map<int, int>::iterator it_bis = ft0.begin();
		ft::map<int, int>::iterator ite = ft0.end();
		CHECK((*it).first == 0);
		CHECK((*it).second == 5);

		/* Equality and non-equality operators (--) */
		CHECK((it != it_bis) == false);
		CHECK((it == it_bis) == true);
		CHECK((++it == it_bis) == false);

		/* Dereference + pre & post increments */
		CHECK((*it++).first == 1);
		CHECK((*it).first == 2);
		CHECK((*++it).first == 3);

		/* Dereference + pre & post decrements */
		CHECK((*it--).first == 3);
		CHECK((*it).first == 2);
		CHECK((*--it).first == 1);
	}
	SUBCASE("reverse iterators") {
		/* rbegin() and rend() */
		ft::map<int, int>::reverse_iterator it_rev = ft0.rbegin();
		ft::map<int, int>::reverse_iterator it_rev2 = ft0.rbegin();
		std::map<int, int>::reverse_iterator it_std = std0.rbegin();

		/* Equality and non-equality operators (--) */
		CHECK((it_rev != it_rev2) == false);
		CHECK((it_rev == it_rev2) == true);
		CHECK((it_rev == ++it_rev2) == false);
	
		/* Dereference + pre & post increments */
		CHECK((*it_rev).first == (*it_std).first);
		CHECK((*++it_rev).first == (*++it_std).first);
		CHECK((*it_rev++).first == (*it_std++).first);
		CHECK((*it_rev).first == (*it_std).first);

		/* Dereference + pre & post decrements */
		CHECK((*--it_rev).first == (*--it_std).first);
		CHECK((*it_rev--).first == (*it_std--).first);
		CHECK((*it_rev).first == (*it_std).first);
	}
}

TEST_CASE("Modifiers and element access")
{
	std::map<int, std::string>	std0;
	ft::map<int, std::string>	ft0;

	std::pair<std::map<int, std::string>::iterator, bool> std_tmp;
	ft::pair<ft::map<int, std::string>::iterator, bool> ft_tmp;

	/* Insert */
	std_tmp = std0.insert(std::pair<int, std::string>(17, "coucou"));
	ft_tmp = ft0.insert(ft::pair<int, std::string>(17, "coucou"));

	// std::cout << printPair(std_tmp.first);
	// std::cout << printPair(ft_tmp.first);
	// std::cout << std_tmp.second << std::endl;
	// std::cout << ft_tmp.second << std::endl;

	std_tmp = std0.insert(std::pair<int, std::string>(17, "lol"));
	ft_tmp = ft0.insert(ft::pair<int, std::string>(17, "lol"));

	// std::cout << printPair(std_tmp.first);
	// std::cout << printPair(ft_tmp.first);
	// std::cout << std_tmp.second << std::endl;
	// std::cout << ft_tmp.second << std::endl;

	/* Operator [] */
	CHECK(std0[17] == ft0[17]);
	std0[17] = "hello sir!";
	ft0[17] = "hello sir!";
	// std::cout << printPair(std_tmp.first);
	// std::cout << printPair(ft_tmp.first);
	// std::cout << std0[17] << std::endl;
	// std::cout << ft0[17] << std::endl;
	CHECK(std0[17] == ft0[17]);

	/* Range constructor */
	std::map<int, std::string>::iterator it_std0 = std0.begin();
	std::map<int, std::string>::iterator ite_std0 = std0.end();
	ft::map<int, std::string>::iterator it_ft0 = ft0.begin();
	ft::map<int, std::string>::iterator ite_ft0 = ft0.end();

	std::map<int, std::string> std1(it_std0, ite_std0);
	ft::map<int, std::string> ft1(it_ft0, ite_ft0);

	/* Erase */
	std0.erase(it_std0, ite_std0);
	ft0.erase(it_ft0, ite_ft0);
}


//////////////////////////////////////////////////
//												//
//					STACK						//
//												//
//////////////////////////////////////////////////

TEST_CASE("Member functions & relational operators") {
	std::stack<int>	std;
	std::stack<int>	std1;
	ft::stack<int>	ft;
	ft::stack<int>	ft1;

	CHECK(std.empty() == ft.empty());

	for (size_t i = 0; i < 100; ++i)
	{
		std.push(i);
		ft.push(i);
	}
	CHECK(std.size() == ft.size());
	CHECK(std.top() == ft.top());

	for (size_t i = 0; i < 42; ++i)
	{
		std.pop();
		ft.pop();
	}
	CHECK(std.size() == ft.size());
	CHECK(std.top() == ft.top());

	std1.push(5);
	ft1.push(5);
	CHECK((ft != ft1) == (std != std1));
	CHECK((ft == ft1) == (std == std1));
	CHECK((ft < ft1) == (std < std1));
	CHECK((ft <= ft1) == (std <= std1));
	CHECK((ft > ft1) == (std > std1));
	CHECK((ft >= ft1) == (std >= std1));

	std::stack<int>	std2(std1);
	ft::stack<int>	ft2(ft1);
	CHECK(std.size() == ft.size());
	CHECK(std.top() == ft.top());
}

//////////////////////////////////////////////////
//												//
//					VECTOR						//
//												//
//////////////////////////////////////////////////

/*
|-----------------------------------------------|
|		1.1 CONSTRUCTORS						|
|-----------------------------------------------|
*/

TEST_CASE("Constructors") {
	std::vector<std::string>	std_v0;
	ft::vector<std::string>		ft_v0;

	std::vector<int>			std_v1(5, 4);
	ft::vector<int>				ft_v1(5, 4);

	int tab[] = {-5, 1, 2, 3, 4, 5};
	std::vector<int>			std_v2(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>				ft_v2(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>				ft_v2bis(ft_v2.begin(), ft_v2.end());

	std::vector<int>			std_v3(std_v2);
	ft::vector<int>				ft_v3(ft_v2);

	SUBCASE("Checking default constructor") {
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
	}
	SUBCASE("Checking fill constructor") {
		CHECK(std_v1.size() == ft_v1.size());
		CHECK(std_v1.capacity() == ft_v1.capacity());
		CHECK(std_v1[0] == ft_v1[0]);
		CHECK(std_v1[3] == ft_v1[3]);
	}
	SUBCASE("Checking range constructor") {	
		CHECK(std_v2.size() == ft_v2.size());
		CHECK(std_v2.capacity() == ft_v2.capacity());
		for (size_t i = 0, n = sizeof(tab) / sizeof(tab[0]); i < n; ++i)
			CHECK(std_v2[i] == ft_v2[i]);
		for (size_t i = 0, n = sizeof(tab) / sizeof(tab[0]); i < n; ++i)
			CHECK(std_v2[i] == ft_v2bis[i]);
	}
	SUBCASE("Checking copy constructor") {	
		CHECK(std_v3.size() == ft_v3.size());
		CHECK(std_v3.capacity() == ft_v3.capacity());
		for (size_t i = 0, n = std_v3.size(); i < n; ++i)
			CHECK(std_v3[i] == ft_v3[i]);
	}
}

/*
|-----------------------------------------------|
|		1.3 ASSIGNMENT OPERATOR					|
|-----------------------------------------------|
*/

TEST_CASE("Assignment operator") {
	int tab[] = {-5, 1, 2, 3, 4, 5};
	int tab1[] = {-2, 5};
	std::vector<int>	std_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	std::vector<int>	std_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));
	ft::vector<int>		ft_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>		ft_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));

	std::vector<int>	std_v2;
	ft::vector<int>		ft_v2;

	std_v2 = std_v0;
	ft_v2 = ft_v0;
	CHECK(std_v2.size() == ft_v2.size());
	CHECK(std_v2.capacity() == ft_v2.capacity());
	for (size_t i = 0, n = sizeof(tab) / sizeof(tab[0]); i < n; ++i)
		CHECK(std_v2[i] == ft_v2[i]);

	std_v0 = std_v1;
	ft_v0 = ft_v1;
	CHECK(std_v0.size() == ft_v0.size());
	CHECK(std_v0.capacity() == ft_v0.capacity());
	for (size_t i = 0, n = std_v0.size(); i < n; ++i)
		CHECK(std_v0[i] == ft_v0[i]);
}

/*
|-----------------------------------------------|
|		1.4 ITERATORS							|
|-----------------------------------------------|
*/

TEST_CASE("Assignment operator") {
	int tab[] = {-5, 1, 2, 3, 4, 5};
	std::vector<int>	std_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>		ft_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));

	SUBCASE("Random Access Iteraotr") {
		/* Constructor & Assignment operator */
		std::vector<int>::iterator	it_std = std_v0.begin();
		std::vector<int>::iterator	it_std1 = it_std;
		std::vector<int>::iterator	it_std2;
		it_std2 = it_std1;
		std::vector<int>::iterator	end_std = std_v0.end();

		ft::vector<int>::iterator	it_ft = ft_v0.begin();
		ft::vector<int>::iterator	it_ft1 = it_ft;
		ft::vector<int>::iterator	it_ft2;
		it_ft2 = it_ft1;
		ft::vector<int>::iterator	end_ft = ft_v0.end();

		/* Dereference operator */
		CHECK(*it_std == *it_ft);
		CHECK(it_std[2] == it_ft[2]);

		/* Increment / Decrement operators */
		CHECK(*it_std++ == *it_ft++);
		CHECK(*it_std-- == *it_ft--);
		CHECK(*++it_std == *++it_ft);
		CHECK(*--it_std == *--it_ft);

		/* Compound assignment operations (+= and -=) */
		CHECK(*(it_std += 3) == *(it_ft += 3));
		CHECK(*(it_std -= 2) == *(it_ft -= 2));

		/* Arithmetic operators (+ and -) */
		CHECK(*(it_std + 3) == *(it_ft + 3));
		CHECK(*(it_std - 1) == *(it_ft - 1));

		/*  Relational operators (==, != <, >, <= and >=) */
		CHECK((it_ft1 == it_ft2) == true);
		CHECK((it_ft1 != end_ft) == true);
		CHECK((it_ft > it_ft1) == true);
		CHECK((it_ft1 < it_ft) == true);
		CHECK((it_ft1 <= it_ft2) == true);
		CHECK((it_ft1 <= end_ft) == true);
		CHECK((it_ft1 >= end_ft) == false);

		/* Arithmetic operators (+ and -) */
		CHECK(*(3 + it_std) == *(3 + it_ft));
		CHECK((end_std - it_std) == (end_ft - it_ft));
	}
	SUBCASE("Reverse iterator") {
		/* Constructor & Assignment operator */
		std::vector<int>::reverse_iterator	it_std = std_v0.rbegin();
		std::vector<int>::reverse_iterator	it_std1 = it_std;
		std::vector<int>::reverse_iterator	it_std2;
		it_std2 = it_std1;
		std::vector<int>::reverse_iterator	end_std = std_v0.rend();

		ft::vector<int>::reverse_iterator	it_ft = ft_v0.rbegin();
		ft::vector<int>::reverse_iterator	it_ft1 = it_ft;
		ft::vector<int>::reverse_iterator	it_ft2;
		it_ft2 = it_ft1;
		ft::vector<int>::reverse_iterator	end_ft = ft_v0.rend();

		/* Dereference operator */
		CHECK(*it_std == *it_ft);
		CHECK(it_std[2] == it_ft[2]);

		/* Increment / Decrement operators */
		CHECK(*it_std++ == *it_ft++);
		CHECK(*it_std-- == *it_ft--);
		CHECK(*++it_std == *++it_ft);
		CHECK(*--it_std == *--it_ft);

		/* Compound assignment operations (+= and -=) */
		CHECK(*(it_std += 3) == *(it_ft += 3));
		CHECK(*(it_std -= 2) == *(it_ft -= 2));

		/* Arithmetic operators (+ and -) */
		CHECK(*(it_std + 3) == *(it_ft + 3));
		CHECK(*(it_std - 1) == *(it_ft - 1));
		CHECK(*(3 + it_std) == *(3 + it_ft));
		CHECK((end_std - it_std) == (end_ft - it_ft));

		/*  Relational operators (==, != <, >, <= and >=) */
		CHECK((it_ft1 == it_ft2) == true);
		CHECK((it_ft1 != end_ft) == true);
		CHECK((it_ft > it_ft1) == true);
		CHECK((it_ft < it_ft1) == false);
		CHECK((it_ft1 <= it_ft2) == true);
		CHECK((it_ft1 <= end_ft) == true);
		CHECK((it_ft1 >= end_ft) == false);
	}
}

/*
|-----------------------------------------------|
|		1.5 CAPACITY							|
|-----------------------------------------------|
*/

TEST_CASE("Capacity member functions") {
	int tab[] = {-5, 1, 2, 3, 4, 5};
	std::vector<int>			std_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>				ft_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	
	SUBCASE("Checking size()") {
		CHECK(std_v0.size() == ft_v0.size());
	}
	SUBCASE("Checking max_size()") {
		CHECK(std_v0.max_size() == ft_v0.max_size());
	}
	SUBCASE("Checking resize()") {
		SUBCASE("n < size && n < capacity") {
			std_v0.resize(4);
			ft_v0.resize(4);
			for (int i = 0, n = std_v0.size(); i < n; ++i)
				CHECK(std_v0[i] == ft_v0[i]);
		}
		SUBCASE("n > size && n < capacity") {
			std_v0.reserve(9); 
			std_v0.resize(7, 2);
			ft_v0.reserve(9); 
			ft_v0.resize(7, 2);
			CHECK(std_v0.capacity() == ft_v0.capacity());
			CHECK(std_v0.size() == ft_v0.size());
			for (int i = 0, n = std_v0.size(); i < n; ++i)
				CHECK(std_v0[i] == ft_v0[i]);
		}
		SUBCASE("n > size && n > capacity") {
			std_v0.resize(7, 17);
			ft_v0.resize(7, 17);
			CHECK(std_v0.capacity() == ft_v0.capacity());
			CHECK(std_v0.size() == ft_v0.size());
			for (int i = 0, n = std_v0.size(); i < n; ++i)
				CHECK(std_v0[i] == ft_v0[i]);
		}
	}
	SUBCASE("Checking capacity()") {
		CHECK(std_v0.capacity() == ft_v0.capacity());
		
	}
	SUBCASE("Checking empty()") {
		CHECK(std_v0.empty() == ft_v0.empty());
	}
	SUBCASE("Checking reserve()") {
		/* try {
			ft_v0.reserve(-3);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		} */
		std_v0.reserve(9);
		ft_v0.reserve(9);
		CHECK(std_v0.capacity() == ft_v0.capacity());
		CHECK(std_v0.size() == ft_v0.size());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
	}
}

/*
|-----------------------------------------------|
|		1.6 ELEMENT ACCESS						|
|-----------------------------------------------|
*/

TEST_CASE("Element access") {
	int tab[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	std::vector<int>			std_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>				ft_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	
	SUBCASE("Checking operator[]") {
		CHECK(std_v0[2] == ft_v0[2]);
	}
	SUBCASE("Checking at()") {
		CHECK(std_v0.at(3) == ft_v0.at(3));
		/* Out-of-bound exception
		std_v0.at(22);
		ft_v0.at(22);
		*/
	}
	SUBCASE("Checking front()") {
		CHECK(std_v0.front() == ft_v0.front());
	}
	SUBCASE("Checking back()") {
		CHECK(std_v0.back() == ft_v0.back());
	}
}

/*
|-----------------------------------------------|
|		1.7 MODIFIERS							|
|-----------------------------------------------|
*/

TEST_CASE("Modifiers") {
	int tab0[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	int tab1[] = {838338, -82828, 28, 3};
	std::vector<int>			std_v0(tab0, tab0 + sizeof(tab0) / sizeof(tab0[0]));
	std::vector<int>			std_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));
	std::vector<int>			std_v2;
	ft::vector<int>				ft_v0(tab0, tab0 + sizeof(tab0) / sizeof(tab0[0]));
	ft::vector<int>				ft_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));
	ft::vector<int>				ft_v2;
	
	SUBCASE("Assign") {
		/* Fill */
		std_v0.assign(3, 12);
		ft_v0.assign(3, 12);
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		std_v1.assign(17, -1);
		ft_v1.assign(17, -1);
		for (size_t i = 0, n = std_v1.size(); i < n; ++i)
			CHECK(std_v1[i] == ft_v1[i]);
		CHECK(std_v1.size() == ft_v1.size());
		CHECK(std_v1.capacity() == ft_v1.capacity());
		std_v2.reserve(5);
		std_v2.assign(3, -222);
		ft_v2.reserve(5);
		ft_v2.assign(3, -222);
		for (size_t i = 0, n = std_v2.size(); i < n; ++i)
			CHECK(std_v2[i] == ft_v2[i]);
		CHECK(std_v2.size() == ft_v2.size());
		CHECK(std_v2.capacity() == ft_v2.capacity());
		
		/* Range */
		std_v2.assign(std_v0.begin(), std_v0.end());
		ft_v2.assign(ft_v0.begin(), ft_v0.end());
		for (size_t i = 0, n = std_v2.size(); i < n; ++i)
			CHECK(std_v2[i] == ft_v2[i]);
		CHECK(std_v2.size() == ft_v2.size());
		CHECK(std_v2.capacity() == ft_v2.capacity());
	}
	SUBCASE("Push back") {
		std_v0.push_back(2928);
		ft_v0.push_back(2928);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		for (size_t i = 0; i < 15; ++i)
		{
			std_v0.push_back(i - 21 * 7);
			ft_v0.push_back(i - 21 * 7);
		}
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		std_v2.push_back(17);
		ft_v2.push_back(17);
		CHECK(std_v2.size() == ft_v2.size());
		CHECK(std_v2.capacity() == ft_v2.capacity());
	}
	SUBCASE("Pop back") {
		std_v0.pop_back();
		ft_v0.pop_back();
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		for (size_t i = 0; i < 4; ++i)
		{
			std_v0.pop_back();
			ft_v0.pop_back();
		}
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		std_v2.pop_back(); // undefined behavior
		ft_v2.pop_back(); // undefined behavior
	}
	SUBCASE("Insert") {
		std::vector<int>::iterator it_begin_std0 = std_v0.begin() + 2;
		ft::vector<int>::iterator it_begin_ft0 = ft_v0.begin() + 2;
		std_v0.insert(it_begin_std0, 5);
		ft_v0.insert(it_begin_ft0, 5);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);

		std::vector<int>::iterator it_begin_std1 = std_v0.begin();
		ft::vector<int>::iterator it_begin_ft1 = ft_v0.begin();
		ft_v0.insert(it_begin_ft1, 5);
		std_v0.insert(it_begin_std1, 5);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);

		std::vector<int>::iterator it_end_std0 = std_v0.end();
		ft::vector<int>::iterator it_end_ft0 = ft_v0.end();
		ft_v0.insert(it_end_ft0, 203);
		std_v0.insert(it_end_std0, 203);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);

		std_v0.insert(std_v0.begin(), 2, -122);
		ft_v0.insert(ft_v0.begin(), 2, -122);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
	
		std::vector<int>::iterator it_begin_std2 = std_v0.begin() + 2;
		ft::vector<int>::iterator it_begin_ft2 = ft_v0.begin() + 2;
		ft_v0.insert(it_begin_ft2, 3, 12);
		std_v0.insert(it_begin_std2, 3, 12);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);

		std::vector<int>::iterator it_pos_std = std_v0.begin() + 2;
		std::vector<int>::iterator it_begin_std = std_v0.begin() + 4;
		std::vector<int>::iterator it_end_std = std_v0.begin() + 8;
		ft::vector<int>::iterator it_pos_ft = ft_v0.begin() + 2;
		ft::vector<int>::iterator it_begin_ft = ft_v0.begin() + 4;
		ft::vector<int>::iterator it_end_ft = ft_v0.begin() + 8;
		std_v0.insert(it_pos_std, it_begin_std, it_end_std);
		ft_v0.insert(it_pos_ft, it_begin_ft, it_end_ft);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
	}
	SUBCASE("Erase") {
		std_v0.erase(std_v0.begin());
		ft_v0.erase(ft_v0.begin());
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		std::vector<int>::iterator it_begin_std = std_v0.begin() + 2;
		std::vector<int>::iterator it_end_std = std_v0.begin() + 5;
		ft::vector<int>::iterator it_begin_ft = ft_v0.begin() + 2;
		ft::vector<int>::iterator it_end_ft = ft_v0.begin() + 5;
		std_v0.erase(it_begin_std, it_end_std);
		ft_v0.erase(it_begin_ft, it_end_ft);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (size_t i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
	}
	SUBCASE("Swap content") {
		std_v0.swap(std_v1);
		ft_v0.swap(ft_v1);
		for (int i = 0, n = std_v0.size(); i < n; ++i)
			CHECK(std_v0[i] == ft_v0[i]);
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		for (int i = 0, n = std_v1.size(); i < n; ++i)
			CHECK(std_v1[i] == ft_v1[i]);
		CHECK(std_v1.size() == ft_v1.size());
		CHECK(std_v1.capacity() == ft_v1.capacity());
	}
	SUBCASE("Clear content") {
		std_v0.clear();
		ft_v0.clear();
		CHECK(std_v0.size() == ft_v0.size());
		CHECK(std_v0.capacity() == ft_v0.capacity());
		std_v0.push_back(18);
		ft_v0.push_back(18);
		CHECK(std_v0[0] == ft_v0[0]);
	}
}

/*
|-----------------------------------------------|
|		1.8 ALLOCATOR							|
|-----------------------------------------------|
*/

TEST_CASE("Allocator") {
	int tab[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	std::vector<int>			std_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));
	ft::vector<int>				ft_v0(tab, tab + sizeof(tab) / sizeof(tab[0]));

	CHECK(std_v0.get_allocator() == ft_v0.get_allocator());
}

/*
|-----------------------------------------------|
|		2.1 RELATIONAL OPERATORS				|
|-----------------------------------------------|
*/

TEST_CASE("Relational operators") {
	int tab0[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	int tab1[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	int tab2[] = {-5, 1, 2, 3, 4, 4, 5};

	ft::vector<int>				ft_v0(tab0, tab0 + sizeof(tab0) / sizeof(tab0[0]));
	ft::vector<int>				ft_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));
	ft::vector<int>				ft_v2(tab2, tab2 + sizeof(tab2) / sizeof(tab2[0]));

	SUBCASE("==") {
		CHECK((ft_v0 == ft_v1) == true);
		CHECK((ft_v0 == ft_v2) == false);
	}
	SUBCASE("!=") {
		CHECK((ft_v0 != ft_v1) == false);
		CHECK((ft_v0 != ft_v2) == true);
	}
	SUBCASE("<") {
		CHECK((ft_v0 < ft_v1) == false);
		CHECK((ft_v2 < ft_v0) == true);
	}
	SUBCASE(">") {
		CHECK((ft_v0 > ft_v1) == false);
		CHECK((ft_v2 > ft_v0) == false);
	}
	SUBCASE("<=") {
		CHECK((ft_v0 <= ft_v1) == true);
		CHECK((ft_v2 <= ft_v0) == true);
	}
	SUBCASE(">=") {
		CHECK((ft_v0 >= ft_v1) == true);
		CHECK((ft_v2 >= ft_v0) == false);
	}
}

/*
|-----------------------------------------------|
|		2.2 SWAP								|
|-----------------------------------------------|
*/

TEST_CASE("Swap") {
	int tab0[] = {-5, 1, 2, 3, 4, 5, -5, 1, 2, 3, 4, 5};
	int tab1[] = {-3838383, 22224, 38882825};
	std::vector<int>			std_v0(tab0, tab0 + sizeof(tab0) / sizeof(tab0[0]));
	std::vector<int>			std_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));
	ft::vector<int>				ft_v0(tab0, tab0 + sizeof(tab0) / sizeof(tab0[0]));
	ft::vector<int>				ft_v1(tab1, tab1 + sizeof(tab1) / sizeof(tab1[0]));

	swap(std_v0, std_v1);
	swap(ft_v0, ft_v1);
	
	for (size_t i = 0, n = std_v0.size(); i < n; ++i)
		CHECK(std_v0[i] == ft_v0[i]);
	for (size_t i = 0, n = std_v1.size(); i < n; ++i)
		CHECK(std_v1[i] == ft_v1[i]);
	CHECK(std_v0.size() == ft_v0.size());
	CHECK(std_v0.capacity() == ft_v0.capacity());
	CHECK(std_v1.size() == ft_v1.size());
	CHECK(std_v1.capacity() == ft_v1.capacity());
}
