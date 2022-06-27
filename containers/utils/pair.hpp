#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template < class T1, class T2 >
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first; // copy of first object
		T2	second; // copy of second object

		/* Constructors */
		pair() : first(), second() {}

		pair(const T1 &a, const T2 &b) : first(a), second(b) {}

		template < class U1, class U2 >
		pair(const pair <U1, U2> &p) : first(p.first), second(p.second) {}

		pair &operator=(const pair &p)
		{
			first = p.first;
			second = p.second;
			return (*this);
		}
	};

	template < class T1, class T2 >
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first == y.first && x.second == y.second);
	}
	template < class T1, class T2 >
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
	}

	template < class T1, class T2 >
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x == y);
	}

	template < class T1, class T2 >
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return y < x;
	}

	template < class T1, class T2 >
	bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(y < x);
	}

	template < class T1, class T2 >
	bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x < y);
	}
} // namespace

#endif
