#ifndef UTILS_HPP
# define UTILS_HPP

#include "IteratorsBaseTypes.hpp"
#include "pair.hpp"

namespace ft {

	/* equal */
	template < typename InputIterator1, typename InputIterator2 >
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	/* lexicographical_compare */
	template < typename InputIterator1, typename InputIterator2 >
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	/* distance */
	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type __distance(InputIterator _first, InputIterator _last, input_iterator_tag)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (_first != _last)
		{
			_first++;
			n++;
		}
		return (n);
	}

	template < class RandomAccessIterator >
	typename iterator_traits<RandomAccessIterator>::difference_type __distance(RandomAccessIterator _first, RandomAccessIterator _last, random_access_iterator_tag)
	{
		return (_last - _first);
	}

	template < class InputIterator >
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		return __distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
	}

	/* make_pair */
	template < class T1, class T2 >
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}

} // namespace

#endif