#ifndef ITERATOR_BASE_TYPES_HPP
# define ITERATOR_BASE_TYPES_HPP

# include <cstddef>

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	/* Common iterator class */
	template<typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	class iterator
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
	};

	/* Traits class for iterators */
	template<typename Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
	};

	/* Partial specialization for pointer types */
	template<typename T>
	class iterator_traits<T*>
	{
		public:
			typedef random_access_iterator_tag		iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
	};

	/* Partial specialization for const pointer types */
	template<typename T>
	class iterator_traits<const T*>
	{
		public:
			typedef random_access_iterator_tag		iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef const T*						pointer;
			typedef const T&						reference;
	};
} // namespace

#endif

/*
Sources:
- https://www.cplusplus.com/reference/iterator/iterator_traits/?kw=iterator_traits
- https://en.cppreference.com/w/cpp/iterator/iterator_traits
- https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator_base_types.h.html
Explanation on iterator traits:
- https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
*/