/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 14:26:48 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>

typedef size_t size_type;
// typedef Allocator allocator_type;

namespace ft
{
	template< typename T, typename Allocator = std::allocator<T> >
	
	class vector
	{
		public:
			//default constructor
			vector( void ) : data(NULL), size(0) {};

			//fill constructor
			explicit vector( size_type size, const T &val ) : size(size)
			{
				Allocator alloc;

				data = alloc.allocate( size );
				for ( size_type i = 0; i < size; i++ )
					alloc.construct(data + i, val);
			};

			//range constructor
			// vector( Iterator first, Iterator last );

			//copy constructor
			vector( const vector &source )
			{
				Allocator alloc;

				for ( size_type i = 0; i < size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, size );
				size = source.size;
				if ( size > 0 )
					data = alloc.allocate( size );
				for ( size_type i = 0; i < size; i++ )
					alloc.construct( data + i, source.data[i] );
			};

			//copy assignement operator
			vector	&operator= ( const vector &source )
			{
				Allocator alloc;

				if ( this != &source )
				{
					for ( size_type i = 0; i < size; i++ )
						alloc.destroy( data + i );
					alloc.deallocate( data, size );
					size = source.size;
					if ( size > 0 )
						data = alloc.allocate( size );
					for ( size_type i = 0; i < size; i++ )
						alloc.construct( data + i, source.data[i] );
				}
				return (*this);
			};

			//destructor
			~vector( void )
			{
				Allocator alloc;
				for ( size_type i = 0; i < size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, size );
				size = 0;
			};

			//[] operator
			T	&operator[]( size_type index ) const
			{
				if ( index >= size )
					throw(std::out_of_range("error: out of range"));
				return ( data[index] );
			};

			//at member function
			T	&at( size_type position ) const
			{
				return (position >= size) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			
			//back memeber function
			T	&back( void ) const
			{
				return (size > 0) ? data[size - 1] : throw(std::out_of_range("error out of range"));
			};

			//empty member function
			bool	empty( void ) const
			{
				return (size == 0) ? true : false;
			};

			
		private:
			T	*data;
			size_type	size;
	};
}
