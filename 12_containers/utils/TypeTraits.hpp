#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

#include <cstdint>

namespace ft {

	/* is_integral */

	template<typename T, T v>
	struct integral_constant
	{
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
	};

	template<typename T, T v>
	const T integral_constant<T, v>::value;

	// The type used as a compile-time boolean with true value.
	typedef integral_constant<bool, true>	true_type;
	// The type used as a compile-time boolean with false value.
	typedef integral_constant<bool, false>	false_type;

	template<typename>
	struct is_integral_helper : public false_type {};

	template<>
	struct is_integral_helper<bool> : public true_type {};

	template<>
	struct is_integral_helper<char> : public true_type {};

	template<>
	struct is_integral_helper<signed char> : public true_type {};

	template<>
	struct is_integral_helper<unsigned char> : public true_type {};

	template<>
	struct is_integral_helper<wchar_t> : public true_type {};

	template<>
	struct is_integral_helper<char16_t> : public true_type {};

	template<>
	struct is_integral_helper<char32_t> : public true_type {};

	template<>
	struct is_integral_helper<short> : public true_type {};

	template<>
	struct is_integral_helper<unsigned short> : public true_type {};

	template<>
	struct is_integral_helper<int> : public true_type {};

	template<>
	struct is_integral_helper<unsigned int> : public true_type {};

	template<>
	struct is_integral_helper<long> : public true_type {};

	template<>
	struct is_integral_helper<unsigned long> : public true_type {};

	template<>
	struct is_integral_helper<long long> : public true_type {};

	template<>
	struct is_integral_helper<unsigned long long> : public true_type {};

	template<typename T>
	struct is_integral : public is_integral_helper<T> {};


	/* enable_if */

	template<bool, typename T = void>
	struct enable_if {};

	// Partial specialization for true.
	template<typename T>
	struct enable_if<true, T> { typedef T type; };

} // namespace

#endif

/*
Sources:
- https://www.cplusplus.com/reference/type_traits/is_integral/
- https://code.woboq.org/gcc/libstdc++-v3/include/std/type_traits.html#std::is_integral
- https://dev.to/sandordargo/what-are-type-traits-in-c-18j5
- https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html

Explanation:
- is_integral is a Trait class that identifies whether T is an integral type.
It inherits from integral_constant as being either true_type or false_type, depending on whether T is an integral type
- Le trait enable_if exprime un type interne et public type
Sa signature est enable_if<bool,T=void> ce qui signifie qu'il est défini sur la base d'une condition statique d'un type (qui sera void par défaut)
L'expression std::enable_if<true,T>::type équivaut à T
L'expression std::enable_if<false,T>::type est indéfinie, ce qui peut éliminer un template de ceux examinés pour la génération du code ou tout simplement bloquer la compilation
*/