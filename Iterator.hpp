/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:44 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/11 15:38:50 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	template < typename  vector >

	class random_access_iterator
	{
		public:
			typedef typename vector::value_type	value_type;
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
}
