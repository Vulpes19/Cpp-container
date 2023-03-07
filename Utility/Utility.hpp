/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:47:35 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/07 14:33:48 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Algorithm/Algorithm.hpp"
#include "../Iterators/Iterator_traits.hpp"

namespace ft
{
	template < typename T1, typename T2 >

	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;
		pair( first_type first, second_type second ) : first(first), second(second)
		{};
		pair    &operator=( const pair &p )
		{
			if (&p != this )
			{
				first = p.first;
				second = p.second;
			}
			return (*this);
		};
		void    swap( pair &p )
		{
			ft::swap(first, p.first);
			ft::swap(second, p.second);
		};
	};

	template< typename T1, typename T2 >
	bool    operator==( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first == p2.first && p1.second == p2.second );
	};

	template< typename T1, typename T2 >
	bool    operator!=( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first != p2.first && p1.second != p2.second );
	};

	template< typename T1, typename T2 >
	bool    operator<=( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first <= p2.first && p1.second <= p2.second );
	};


	template< typename T1, typename T2 >
	bool    operator<( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first < p2.first && p1.second < p2.second );
	};

	template< typename T1, typename T2 >
	bool    operator>=( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first >= p2.first && p1.second >= p2.second );
	};

	template< typename T1, typename T2 >
	bool    operator>( const pair<T1, T2> &p1, const pair<T1, T2> &p2 )
	{
		return ( p1.first > p2.first && p1.second > p2.second );
	};

	template < typename T1, typename T2 >
	void	swap( pair<T1, T2> &p1, pair<T1, T2> &p2 )
	{
		p1.swap(p2);
	};

	template < typename T1, typename T2 >

	pair< T1, T2 >	make_pair( T1 x, T2 y )
	{
		pair<T1, T2> p(x, y);
		return (p);
	};
}