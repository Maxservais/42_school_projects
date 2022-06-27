#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <ostream>
#include <memory>
#include "../utils/TypeTraits.hpp"
#include "../utils/RandomAccessIterator.hpp"
#include "../utils/ReverseIterator.hpp"
#include "../utils/utils.hpp"

namespace ft {

template < typename T, class Alloc = std::allocator<T> >
class vector
{

	public:

		/*
		|-----------------------------------------------------------------------------------|
		|																					|
		|		0. MEMBER TYPES																|
		|																					|
		|-----------------------------------------------------------------------------------|
		*/
		
		typedef	T														value_type;
		typedef	Alloc													allocator_type;
		typedef	typename allocator_type::reference						reference;
		typedef	typename allocator_type::const_reference				const_reference;
		typedef	typename allocator_type::pointer						pointer;
		typedef	typename allocator_type::const_pointer					const_pointer;
		typedef typename ft::random_access_iterator<T>					iterator;
		typedef typename ft::random_access_iterator<const T>			const_iterator;
		typedef	typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef	std::size_t												size_type;

		/*
		|-----------------------------------------------------------------------------------|
		|																					|
		|		1. MEMBER FUNCTIONS															|
		|																					|
		|-----------------------------------------------------------------------------------|
		*/

		/*
		|-----------------------------------------------|
		|		1.1 CONSTRUCTORS						|
		|-----------------------------------------------|
		*/

		/* 1.1.1 Default constructor - constructs an empty container, with no elements.
		----------------------------------------------------------------------------- */
		explicit vector(const allocator_type &alloc = allocator_type()): 
		_alloc(alloc),
		_vec(NULL),
		_size(0),
		_capacity(0)
		{
			return ;
		}

		/* 1.1.2 Fill constructor - constructs a container with n elements. Each element is a copy of val.
		----------------------------------------------------------------------------- */
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
		_alloc(alloc)
		{
			if (n > this->_alloc.max_size())
				throw std::length_error("vector");
			else
			{
				this->_size = n;
				this->_capacity = n; 
				this->_vec = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < n; ++i)
					this->_alloc.construct(this->_vec + i, val);
			}
			return ;
		}

		/* 1.1.3 Range constructor - constructs a container with as many elements as 
		the range [first,last], with each element constructed from its corresponding element in that range, in the same order.
		----------------------------------------------------------------------------- */
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) :
		_alloc(alloc)
		{
			this->_size = ft::distance(first, last);
			this->_capacity = this->_size;
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; ++i, ++first)
				this->_alloc.construct(this->_vec + i, *first);
			return ;
		}

		/* 1.1.4 Copy constructor - constructs a container with a copy of each of the elements in x, in the same order.
		----------------------------------------------------------------------------- */
		vector(const vector& x) :
		_alloc(x._alloc),
		_size(x._size),
		_capacity(x._capacity)
		{
			this->_vec = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; ++i)
				this->_alloc.construct(this->_vec + i, x._vec[i]);
			return ;
		}

		/*
		|-----------------------------------------------|
		|		1.2 DESTRUCTOR							|
		|-----------------------------------------------|
		*/

		/* 1.2.1 Default Destructor - destroys the container object
		----------------------------------------------------------------------------- */
		~vector()
		{
			for (size_type i = 0; i < this->_size; ++i)
				this->_alloc.destroy(this->_vec + i);
			this->_alloc.deallocate(this->_vec, this->_capacity);
			return ;
		}

		/*
		|-----------------------------------------------|
		|		1.3 ASSIGNMENT OPERATOR					|
		|-----------------------------------------------|
		*/

		/* 1.3.1 Assignment operator - copies all the elements from x into the container
		----------------------------------------------------------------------------- */
		vector& operator=(const vector &x)
		{
			if (this != &x)
				this->assign(x.begin(), x.end());
			return (*this);
		}

		/*
		|-----------------------------------------------|
		|		1.4 ITERATORS							|
		|-----------------------------------------------|
		*/

		/* 1.4.1 begin() - Returns an iterator pointing to the first element in the vector.
		----------------------------------------------------------------------------- */
		iterator begin()
		{
			return (this->_vec);
		}

		const_iterator begin() const
		{
			return (this->_vec);
		}

		/* 1.4.2 end() - Returns an iterator referring to the past-the-end element in the vector container.
		----------------------------------------------------------------------------- */
		iterator end()
		{
			return (this->_vec + this->size());
		}
		
		const_iterator end() const
		{
			return (this->_vec + this->size());
		}

		/* 1.4.3 rbegin() - Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
		----------------------------------------------------------------------------- */
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		
		/* 1.4.4 rend() - Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
		----------------------------------------------------------------------------- */
		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		/*
		|-----------------------------------------------|
		|		1.5 CAPACITY							|
		|-----------------------------------------------|
		*/

		/* 1.5.1 size() - number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
		----------------------------------------------------------------------------- */
		size_type size() const
		{
			return (this->_size);
		}

		/* 1.5.2 max_size() - returns the maximum number of elements that the vector can hold.
		----------------------------------------------------------------------------- */
		size_type max_size() const
		{
			return (this->_alloc.max_size());
		}
		
		/* 1.5.3 resize() - resizes the container so that it contains n elements.
		----------------------------------------------------------------------------- */
		void resize(size_type n, value_type val = value_type())
		{
			if (n < this->size())
			{
				for (size_type i = n, len = this->size(); i < len; ++i)
					this->_alloc.destroy(this->_vec + i);
			}
			else if (n > this->size() && n > this->capacity())
			{
				if (this->_size * 2 >= n)
					reserve(this->size() * 2);
				else
					reserve(n);
			}
			if (n > this->size() && n <= this->capacity())
			{
				for (size_type i = this->size(); i < n; ++i)
					this->_alloc.construct(this->_vec + i, val);
			}
			this->_size = n;
		}
 
		/* 1.5.4 capacity() - returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		----------------------------------------------------------------------------- */
		size_type capacity() const
		{
			return (this->_capacity);
		}

		/* 1.5.5 empty() - returns whether the vector is empty (i.e. whether its size is 0).
		----------------------------------------------------------------------------- */
		bool empty() const
		{
			return (this->_size == 0);
		}

		/* 1.5.6 reserve() - requests that the vector capacity be at least enough to contain n elements.
		----------------------------------------------------------------------------- */
		void reserve(size_type n)
		{
			if (n > this->_alloc.max_size())
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			else if (n > this->_capacity)
			{
				/* Declare new pointer */
				pointer	new_vec;
			
				/* Allocate n blocks of memory for the new vector */
				new_vec = this->_alloc.allocate(n);

				/* Copy content inside the new vector */
				size_type old_size = this->size();
				for (size_type i = 0; i < this->_size; ++i)
					this->_alloc.construct(new_vec + i, this->_vec[i]);
			
				/* Erase elements from old memory area and deallocate */
				this->clear();
				this->_alloc.deallocate(this->_vec, this->_capacity);

				/* Swap our 'old' vector for the new one */
				this->_vec = new_vec;
				this->_size = old_size;
				this->_capacity = n;
			}
			return ;
		}


		/*
		|-----------------------------------------------|
		|		1.6 ELEMENT ACCESS						|
		|-----------------------------------------------|
		*/

		/* 1.6.1 operator[] - returns a reference to the element at position n in the vector container.
		----------------------------------------------------------------------------- */
		reference operator[](size_type n)
		{
			return (*(this->_vec + n));
		}

		const_reference operator[](size_type n) const
		{
			return (*(this->_vec + n));
		}

		/* 1.6.2 at() - returns a reference to the element at position n in the vector.
		----------------------------------------------------------------------------- */
		reference at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector");
			return (*(this->_vec + n));
		}

		const_reference at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector");
			return (*(this->_vec + n));
		}

		/* 1.6.3 front() - returns a reference to the first element in the vector.
		----------------------------------------------------------------------------- */
		reference front()
		{
			return (this->at(0));
		}

		const_reference front() const
		{
			return (this->at(0));
		}

		/* 1.6.4 back() - returns a reference to the last element in the vector.
		----------------------------------------------------------------------------- */
		reference back()
		{
			return (this->at(this->_size - 1));
		}

		const_reference back() const
		{
			return (this->at(this->_size - 1));
		}

		/*
		|-----------------------------------------------|
		|		1.7 MODIFIERS							|
		|-----------------------------------------------|
		*/

		/* 1.7.1 assign() - assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		----------------------------------------------------------------------------- */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
		{
			size_type len = ft::distance(first, last);
			if (len > this->capacity())
				this->reserve(len);
			this->clear();
			for (size_type i = 0; i < len; ++i)
				this->_alloc.construct(this->_vec + i, *first++);
			this->_size = len;
		}

		void assign(size_type n, const value_type& val)
		{
			if (n > this->capacity())
				this->reserve(n);
			this->clear();
			for (size_type i = 0; i < n; ++i)
				this->_alloc.construct(this->_vec + i, val);
			this->_size = n;
		}

		/* 1.7.2 push_back() - adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		----------------------------------------------------------------------------- */
		void push_back(const value_type& val)
		{
			if (this->size() == this->capacity())
			{
				if (this->_capacity == 0)
					this->reserve(1);
				else
					this->reserve(this->_capacity * 2);
			}
			this->_alloc.construct(this->_vec + this->_size, val);
			this->_size++;
			return ;
		}

		/* 1.7.3 pop_back() - removes the last element in the vector, effectively reducing the container size by one.
		----------------------------------------------------------------------------- */
		void pop_back()
		{
			if (this->_size > 0)
			{
				this->_size--;
				this->_alloc.destroy(this->_vec + this->_size);
			}
			return ;
		}

		/* 1.7.4 insert() - the vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
		----------------------------------------------------------------------------- */
		iterator insert(iterator position, const value_type& val)
		{
			/* Find offset */
			size_type dist = ft::distance(this->begin(), position);

			/* Allocate more memory if needed */
			if (this->size() + 1 > this->capacity())
				resize(this->size() + 1);
			else
			{
				for (size_type i = this->size(); i < this->size() + 1; ++i)
					this->_alloc.construct(this->_vec + i, val);
				this->_size = this->size() + 1;
			}

			/* Start moving elements to leave sufficient room for the element to be inserted */
			iterator it_tmp = this->begin() + dist;
			for (iterator it_end = this->end() - 1; it_end != it_tmp; it_end--)
			{
				*(it_end) = *(it_end - 1);
			}

			/* Insert val */
			*it_tmp = val;

			/* Return iterator that points to the newly inserted element */
			return (it_tmp);
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			/* Error checking */
			if (n <= 0)
				return ;

			/* Find offset */
			size_type dist = ft::distance(this->begin(), position);

			/* Allocate more memory if needed */
			if (this->size() + n > this->capacity())
				resize(this->size() + n);
			else
			{
				for (size_type i = this->size(); i < this->size() + n; ++i)
					this->_alloc.construct(this->_vec + i, val);
				this->_size = this->size() + n;
			}

			/* Start moving elements to leave sufficient room for the elements to be inserted */
			iterator it_tmp = this->begin() + dist;
			for (iterator it_end = this->end() - 1; it_end != it_tmp + 1; it_end--)
			{
				*(it_end) = *(it_end - n);
			}

			/* Insert val */
			for (size_type i = 0; i < n; ++i)
				*(it_tmp + i) = val;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
		{
			size_type i = 0;

			/* Find offset */
			size_type pos = ft::distance(this->begin(), position);
		
			/* Find number of elements to insert */
			size_type n = ft::distance(first, last);

			/* Make sure we get enough space for the elements */
			reserve(this->size() + n);

			/* Update back iterator (was invalidated when we called reserve) */
			position = begin() + pos;

			/* Copy the elements to the end */
			for (iterator it_tmp = this->end() + n - 1; it_tmp >= position + n; it_tmp--)
				*it_tmp = *(it_tmp - n);
			for (InputIterator it_tmp = first; it_tmp != last; it_tmp++)
			{
				this->_alloc.construct(&position[i], *it_tmp);
				i++;
			}
			this->_size += n;
		}

		/* 1.7.5 erase() - removes from the vector either a single element (position) or a range of elements ([first,last]).
		----------------------------------------------------------------------------- */
		iterator erase(iterator position)
		{
			iterator tmp = position;

			this->_alloc.destroy(tmp.base());
			for (iterator it = tmp + 1; it != this->end(); ++it, ++tmp)
				*tmp = *it;
			this->_alloc.destroy(this->_vec + this->_size);
			this->_size--;
			return (position);
		}

		iterator erase(iterator first, iterator last)
		{
			pointer ptr = this->_vec + (first - this->begin());
			size_type diff = ft::distance(first, last);

			for (size_type i = 0; i < diff - 1; ++i)
				this->_alloc.destroy(ptr + i);
			for (iterator it = ptr + diff; it != this->end(); ++it, ++ptr)
				*ptr = *it;
			for (size_type i = 0; i < diff; ++i)
				this->_alloc.destroy(this->_vec + this->_size - i);
			this->_size -= diff;
			return (first);
		}

		/* 1.7.6 swap() - exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		----------------------------------------------------------------------------- */
		void swap(vector& x)
		{
			std::swap(this->_size, x._size);
			std::swap(this->_capacity, x._capacity);
			std::swap(this->_vec, x._vec);
		}

		/* 1.7.6 clear() - removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		----------------------------------------------------------------------------- */
		void clear()
		{
			while (this->_size > 0)
			{
				this->_alloc.destroy(this->_vec + this->_size - 1);
				this->_size--;
			}
			return ;
		}

		/*
		|-----------------------------------------------|
		|		1.8 ALLOCATOR							|
		|-----------------------------------------------|
		*/
		
		/* 1.8.1 get_allocator() - returns a copy of the allocator object associated with the vector.
		----------------------------------------------------------------------------- */
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

	private:

		allocator_type	_alloc;
		pointer			_vec;
		size_type		_size;
		size_type		_capacity;

} ;

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
template <class T, class Alloc>
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
}

/*
|-----------------------------------------------|
|		2.2 SWAP								|
|-----------------------------------------------|
*/

/* 2.2.1 swap() - the contents of container x are exchanged with those of y. Both container objects must be of the same type (same template parameters), although sizes may differ.
----------------------------------------------------------------------------- */
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

} // namespace

#endif
