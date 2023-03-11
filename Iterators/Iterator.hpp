/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:44 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/11 10:45:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Iterator_traits.hpp"
#include "../TypeTraits/TypeTraits.hpp"

namespace ft
{
	template < typename  T >

	class random_access_iterator
	{
		public:
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T*						const_pointer;
			typedef const T& 						const_reference;
			typedef	std::random_access_iterator_tag iterator_category;
			typedef size_t 							size_type;

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
			~random_access_iterator( void ) {};

			operator    random_access_iterator<const T>()
            {
                return (random_access_iterator<const T>(data));
            }

			bool	operator==( const random_access_iterator &it ) const
			{
				return ( data == it.data );
			};			
			bool	operator!=( const random_access_iterator &it ) const
			{
				return ( data != it.data );
			};
			reference	operator*( void )
			{
				return (*data);
			};
			pointer		operator->( void )
			{
				return (data);
			};

			const_reference	operator*( void ) const
			{
				return (*data);
			};
			const_pointer		operator->( void ) const
			{
				return (data);
			};

			random_access_iterator	operator++( int )
			{
				random_access_iterator it = *this;
				data++;
				return (it);
			};		
			random_access_iterator	operator--( int )
			{
				random_access_iterator it = *this;
				data--;
				return (it);
			};
			random_access_iterator	&operator++( void )
			{
				data++;
				return (*this);
			};		
			random_access_iterator	&operator--( void )
			{
				data--;
				return (*this);
			};		
			random_access_iterator	operator+( const difference_type &n )
			{
				return (random_access_iterator(data + n));
			};		
			random_access_iterator	operator-( const difference_type &n )
			{
				return (random_access_iterator(data - n));
			};
			friend	random_access_iterator	operator+( size_type n, random_access_iterator it )
			{
				return ( it + n );
			}
			friend	random_access_iterator	operator-( size_type n, random_access_iterator it )
			{
				return ( it - n );
			}

			difference_type	operator-( const random_access_iterator &it ) const
			{
				return (data - it.data);
			};
			template<typename U>
			bool	operator<( const random_access_iterator<U> &it ) const
			{
				return ( data < it.base() );
			};
			template<typename U>
			bool	operator<=( const random_access_iterator<U> &it ) const
			{
				return ( data <= it.base() );
			};		
			template<typename U>
			bool	operator>( const random_access_iterator<U> &it ) const
			{
				return ( data > it.base() );
			};
			template<typename U>
			bool	operator>=( const random_access_iterator<U> &it ) const
			{
				return ( data >= it.base() );
			};				
			random_access_iterator	&operator+=( size_type n )
			{
				data += n;
				return (*this);
			};
			random_access_iterator	&operator-=( size_type n )
			{
				data -= n;
				return (*this);
			};
			reference	operator[]( size_type index ) const
			{
				return (data[index]);
			};

			pointer	base( void ) const
			{
				return (data);
			}
		private:
			pointer	data;
	};
	template< typename iterator_type >

	class reverse_iterator
	{
		public:
			typedef typename iterator_type::value_type			value_type;
			typedef	typename iterator_type::pointer				pointer;
			typedef typename iterator_type::difference_type		difference_type;
			typedef typename iterator_type::iterator_category	iterator_category;
			typedef value_type&									reference;
			typedef size_t 										size_type;
		
			reverse_iterator( void ) {};
			explicit	reverse_iterator( iterator_type it ) : it(it) {};
			template < typename Iter >
			reverse_iterator( const reverse_iterator<Iter> &rev_it ) : it(rev_it.base()) {};
			pointer	operator->( void ) const
			{
				iterator_type tmp = it;
				tmp--;
				return (tmp.operator->());
			};
			reference	operator*( void ) const
			{
				iterator_type tmp = it;
				tmp--;
				return (*tmp);
			};
			reference	operator[]( size_type index ) const
			{
				iterator_type ret = it;

				ret -= index + 1;
				return (*ret);
			};
			reverse_iterator	&operator++( void )
			{
				it--;
				return (*this);
			};
			reverse_iterator	&operator--( void )
			{
				it++;
				return (*this);
			};
			reverse_iterator	operator++( int )
			{
				reverse_iterator tmp = *this;
				it--;
				return (tmp);
			};		
			reverse_iterator	operator--( int )
			{
				reverse_iterator tmp = *this;
				it++;
				return (tmp);
			};
			reverse_iterator	&operator+=( difference_type n )
			{
				it -= n;
				return (*this);
			};
			reverse_iterator	&operator-=( difference_type n )
			{
				it += n;
				return (*this);
			};
			reverse_iterator	operator+( const difference_type &n )
			{
				return (reverse_iterator(it - n));
			};		
			reverse_iterator	operator-( const difference_type &n )
			{
				return (reverse_iterator(it + n));
			};
			difference_type	operator+( const reverse_iterator &rev )
			{
				return (it + rev.it);
			};		
			difference_type	operator-( const reverse_iterator &rev )
			{
				return -(it - rev.it);
			};
			reverse_iterator	operator+( const difference_type &n ) const
			{
				return (reverse_iterator(it + n));
			};		
			reverse_iterator	operator-( const difference_type &n ) const
			{
				return (reverse_iterator(it - n));
			};
			friend reverse_iterator	operator+( const difference_type &n, reverse_iterator rev )
			{
				return reverse_iterator(rev + n);
			};		
			friend reverse_iterator	operator-( const difference_type &n, reverse_iterator rev )
			{
				return reverse_iterator(rev - n);
			};
			template <typename U>
			bool	operator==( const reverse_iterator<U> &rev) const
			{
				return ( this->it == rev.base() );
			};
			template <typename U>
			bool	operator!=( const reverse_iterator<U> &rev ) const
			{
				return ( this->it != rev.base() );
			};
			template <typename U>
			bool	operator<( const reverse_iterator<U> &rev ) const
			{
				return ( this->it > rev.base() );
			};
			template <typename U>
			bool	operator<=( const reverse_iterator<U> &rev ) const
			{
				return ( this->it >= rev.base() );
			};
			template <typename U>
			bool	operator>( const reverse_iterator<U> &rev ) const
			{
				return ( this->it < rev.base() );
			};
			template <typename U>
			bool	operator>=( const reverse_iterator<U> &rev ) const
			{
				return ( this->it <= rev.base() );
			};
			iterator_type base( void ) const
			{
				return (it);
			}
		private:
			iterator_type it;
	};
}
