/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:44 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/09 15:13:36 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
	template < typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T& >

	class random_access_iterator
	{
		public:
			typedef T   value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;

			random_access_iterator( void ) : data(NULL) {};			
			random_access_iterator( const random_access_iterator &it );
			random_access_iterator	&operator=( const random_access_iterator &it );
			~random_access_iterator( void );
			bool	operator==( const random_access_iterator &it ) const
			{
				return 
			};			
			bool	operator!=( const random_access_iterator &it ) const;
			reference	operator*( const random_access_iterator &it ) const;
			pointer		operator->( const random_access_iterator &it ) const;
			random_access_iterator	&operator++( void );		
			random_access_iterator	&operator--( void );
			random_access_iterator	&operator++( int );		
			random_access_iterator	&operator--( int );
			random_access_iterator	&operator+( const int &n );		
			random_access_iterator	&operator-( const int &n );		
			random_access_iterator	&operator-( const random_access_iterator &it );
			bool	operator<( const random_access_iterator &it ) const;		
			bool	operator<=( const random_access_iterator &it ) const;		
			bool	operator>( const random_access_iterator &it ) const;		
			bool	operator>=( const random_access_iterator &it ) const;
			random_access_iterator	&operator+=( int n );
			random_access_iterator	&operator-=( int n );
			value_type	&operator[]( size_t index ) const;
		private:
			value_type	*data;
	};
}
