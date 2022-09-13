#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		/*
		|-----------------------------------------------------------------------------------|
		|																					|
		|		0. MEMBER TYPES																|
		|																					|
		|-----------------------------------------------------------------------------------|
		*/
		public:
			
			typedef	Container							container_type;
			typedef	typename container_type::value_type	value_type;
			typedef	typename container_type::size_type	size_type;

		protected:

			container_type	c;

		/*
		|-----------------------------------------------------------------------------------|
		|																					|
		|		1. MEMBER FUNCTIONS															|
		|																					|
		|-----------------------------------------------------------------------------------|
		*/
		public:

			/* 1.1 Constructors - A container adaptor keeps internally a container object as data.
			This container object is a copy of the ctnr argument passed to the constructor, if any, otherwise it is an empty container.
			----------------------------------------------------------------------------- */
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}

			stack(const stack & rhs) : c(rhs.c) {}

			stack &operator=(const stack &rhs) { this->c = rhs.c; return (*this); }

			/* 1.2 Default Destructor - destroys the container object
			----------------------------------------------------------------------------- */
			~stack() {}

			/* 1.3 empty() - test whether container is empty
			----------------------------------------------------------------------------- */
			bool empty() const { return this->c.empty(); }

			/* 1.4 size() - returns the number of elements in the stack.
			----------------------------------------------------------------------------- */
			size_type size() const { return this->c.size(); }

			/* 1.5 top() - returns a reference to the top element in the stack. 
			----------------------------------------------------------------------------- */
			value_type &top() { return this->c.back(); }

			const value_type &top() const { return this->c.back(); }

			/* 1.6 push() - inserts a new element at the top of the stack, above its current top element.
			----------------------------------------------------------------------------- */
			void push(const value_type& val) { this->c.push_back(val); }

			/* 1.7 pop() - removes the element on top of the stack, effectively reducing its size by one.
			----------------------------------------------------------------------------- */
			void pop() { this->c.pop_back(); };

			/* 1.8 Relational operators.
			----------------------------------------------------------------------------- */
			template <class T1, class _C1>
			friend bool operator==(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs) { return (lhs.c == rhs.c); }

			template <class T1, class _C1>
			friend bool operator<(const stack<T1, _C1> &lhs, const stack<T1, _C1> &rhs) { return (lhs.c < rhs.c); }

	};

	/*
	|-----------------------------------------------------------------------------------|
	|																					|
	|	2. NON-MEMBER FUNCTION OVERLOADS												|
	|																					|
	|-----------------------------------------------------------------------------------|
	*/

	/*
	|-----------------------------------------------|
	|		2.1 RELATIONAL OPERATORS				|
	|-----------------------------------------------|
	*/

	/* 2.1.1 Relational operators - performs the appropriate comparison operation between the vector containers lhs and rhs.
	----------------------------------------------------------------------------- */
	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
} // namespace

#endif