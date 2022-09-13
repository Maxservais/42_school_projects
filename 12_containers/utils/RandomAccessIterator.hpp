#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "IteratorsBaseTypes.hpp"

namespace ft {

template < typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

	public:

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;

	protected:

		pointer	_ptr;

	public:

		/* Default constructor
		----------------------------------------------------------------------------- */
		random_access_iterator(void) : _ptr(NULL) {}

		random_access_iterator(pointer ptr) : _ptr(ptr) {}

		/* Copy constructor
		----------------------------------------------------------------------------- */
		random_access_iterator(random_access_iterator const &other) : _ptr(other._ptr) {}

		/* Default Destructor
		----------------------------------------------------------------------------- */
		~random_access_iterator(void) {}

		/* Assignment operator
		----------------------------------------------------------------------------- */
		random_access_iterator &operator=(random_access_iterator const &rhs)
		{
			if (this != &rhs)
				this->_ptr = rhs._ptr;
			return (*this);
		}

		/* Base()
		----------------------------------------------------------------------------- */
		pointer const &base() const
		{
			return (this->_ptr);
		}

		/* Casting to const
		----------------------------------------------------------------------------- */
		operator random_access_iterator<const T>() const
		{
			return (this->_ptr);
		}

		/* Dereference operator
		----------------------------------------------------------------------------- */
		reference operator*() const
		{
			return (*this->_ptr);
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		/* Offset dereference operator ([])
		----------------------------------------------------------------------------- */
		reference operator[](difference_type n) const
		{
			return (this->_ptr[n]);
		}

		/* Pre and postfix Increment operators (++)
		----------------------------------------------------------------------------- */
		random_access_iterator &operator++()
		{
			++this->_ptr;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			operator++(); // prefix-increment this instance
			return (tmp); // return value before increment
		}

		/* Pre and postfix Decrement operators (--)
		----------------------------------------------------------------------------- */
		random_access_iterator &operator--()
		{
			--this->_ptr;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			operator--(); // prefix-decrement this instance
			return (tmp); // return value before increment
		}

		/* Arithmetic operators (+ and -)
		----------------------------------------------------------------------------- */
		random_access_iterator operator+(difference_type n) const
		{
			return (random_access_iterator(this->_ptr + n));
		}

		random_access_iterator operator-(difference_type n) const
		{
			return (random_access_iterator(this->_ptr - n));
		}

		/* Compound assignment operations (+= and -=)
		----------------------------------------------------------------------------- */
		random_access_iterator &operator+=(difference_type n)
		{
			this->_ptr += n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			this->_ptr -= n;
			return (*this);
		}
} ;


/*  Relational operators (==, != <, >, <= and >=)
----------------------------------------------------------------------------- */
template < typename IteratorL, typename IteratorR >
bool operator==(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (lhs.base() == rhs.base());
}

template < typename IteratorL, typename IteratorR >
bool operator!=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (!(lhs.base() == rhs.base()));
}

template < typename IteratorL, typename IteratorR >
bool operator<(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (lhs.base() < rhs.base());
}

template < typename IteratorL, typename IteratorR >
bool operator>(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (rhs.base() < lhs.base());
}

template < typename IteratorL, typename IteratorR >
bool operator<=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (!(rhs.base() < lhs.base()));
}

template < typename IteratorL, typename IteratorR >
bool operator>=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (!(lhs.base() < rhs.base()));
}


/* Arithmetic operators (+ and -)
----------------------------------------------------------------------------- */
template < typename Iterator >
random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> const &rhs)
{
	return (rhs.base() + n);
}

template < typename IteratorL, typename IteratorR >
typename random_access_iterator<IteratorL>::difference_type operator-(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
{
	return (lhs.base() - rhs.base());
}

} // namespace

#endif

/*
Sources:
- https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
- https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

Explanation:
- Random-access iterators are iterators that can be used to access elements at an arbitrary
offset position relative to the element they point to, offering the same functionality as pointers.
*/