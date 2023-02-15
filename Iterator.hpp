/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:44 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/15 16:33:43 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "TypeTraits.hpp"

namespace ft
{
	template< typename InputIterator >
	size_t	ft_distance( InputIterator first, InputIterator last )
	{
		size_t size = 0;
		for ( ;first != last; ++first )
			size++;
		return (size);
	}
	template < typename  T >

	class random_access_iterator
	{
		public:
			typedef T				value_type;
			typedef ptrdiff_t		difference_type;
			typedef value_type*		pointer;
			typedef value_type&		reference;

			random_access_iterator( void ) : data(NULL) {};
			random_access_iterator( pointer newData ) : data(newData) {};			
			random_access_iterator( const random_access_iterator &it )
			{
				data = it.data;
			};
			random_access_iterator	&operator=( const random_access_iterator &it )
			{
				if (this != &it)
				{
					data = it.data;
				}
				return *this;
			};
			~random_access_iterator( void )
			{};
			bool	operator==( const random_access_iterator &it ) const
			{
				return ( data == it.data );
			};			
			bool	operator!=( const random_access_iterator &it ) const
			{
				return ( data != it.data );
			};
			reference	operator*( void ) const
			{
				return (*data);
			};
			pointer		operator->( void ) const
			{
				return (data);
			};
			random_access_iterator	&operator++( void )
			{
				data++;
				return (*this);
			};		
			random_access_iterator	&operator--( void )
			{
				data++;
				return (*this);
			};
			random_access_iterator	operator++( int )
			{
				random_access_iterator it = *this;
				++data;
				return (it);
			};		
			random_access_iterator	operator--( int )
			{
				random_access_iterator it = *this;
				--data;
				return (it);
			};		
			random_access_iterator	&operator+( const int &n )
			{
				data += n;
				return (*this);
			};		
			random_access_iterator	&operator-( const int &n )
			{
				data -= n;
				return (*this);
			};		
			size_t	operator-( const random_access_iterator &it ) const
			{
				return (data - it.data);
			};
			bool	operator<( const random_access_iterator &it ) const
			{
				return ( data < it.data );
			};		
			bool	operator<=( const random_access_iterator &it ) const
			{
				return ( data <= it.data );
			};		
			bool	operator>( const random_access_iterator &it ) const
			{
				return ( data > it.data );
			};				
			bool	operator>=( const random_access_iterator &it ) const
			{
				return ( data > it.data );
			};				
			random_access_iterator	&operator+=( int n )
			{
				data += n;
				return (*this);
			};
			random_access_iterator	&operator-=( int n )
			{
				data -= n;
				return (*this);
			};;
			reference	operator[]( size_t index ) const
			{
				return (data[index]);
			};

		private:
			value_type	*data;
	};

	template< typename iterator_type >

	class reverse_iterator
	{
		public:
			reverse_iterator( void );
			explicit	reverse_iterator( iterator_type it );
			template < typename Iter >
			reverse_iterator( typename ft::enable_if<!ft::is_integral<Iter>::value, typename reverse_iterator>::type<Iter> const &rev_it );
			
	};
}
