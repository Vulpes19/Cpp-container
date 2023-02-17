/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:50:24 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/17 16:04:11 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Iterators/Iterator_traits.hpp"

namespace ft
{
	template < typename InputIterator >
	typename ft::iterator_traits<InputIterator>::difference_type calculate( InputIterator first, InputIterator last, std::random_access_iterator_tag )
	{
		return ( last - first );
	}

	template < typename InputIterator >
	typename ft::iterator_traits<InputIterator>::difference_type	calculate( InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type size = 0;
		for ( ;first != last; ++first )
			size++;
		return (size);
	}
	template < typename InputIterator >
	typename ft::iterator_traits<InputIterator>::difference_type	distance( InputIterator first, InputIterator last )
	{
		return (calculate(first, last, typename ft::iterator_traits<InputIterator>::iterator_category()));
	}

	template < typename T >
	void	swap( T &a, T &b )
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template < typename InputIterator1, typename InputIterator2 >

	bool	equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		for ( ; first1 != last1; ++first1 )
		{
			if ( *first1 != *first2) return (false);
			++first2;
		}
		return (true);
	}

	template < typename InputIterator1, typename InputIterator2, typename BinaryPredicate >

	bool	equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred )
	{
		for ( ; first1 != last1; ++first1 )
		{
			if ( !pred( *first1, *first2 )) return (false);
			++first2;
		}
		return (true);
	}

	template < typename InputIterator1, typename InputIterator2 >

	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
	{
		for ( ; first1 != last1; ++first1, ++first2 )
		{
			if ( *first1 < *first2 ) return (true);
			if ( *first2 < *first1 ) return (false);
		}
		return ( first2 != last2 );
	}

	template < typename InputIterator1, typename InputIterator2, typename Compare >

	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp )
	{
		for ( ; first1 != last1; ++first1 )
		{
			if ( comp( *first1, *first2 ) ) return ( true );
			if ( comp( *first2, *first1 ) ) return ( false );
		}
		return ( first1 == last1 && first2 != last2 );
	}

}