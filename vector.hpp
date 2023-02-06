/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 15:20:17 by abaioumy         ###   ########.fr       */
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
			vector( void ) : data(NULL), _size(0), _capacity(0) {};

			//fill constructor
			explicit vector( size_type size, const T &val ) : _size(size), _capacity(size)
			{
				Allocator alloc;

				data = alloc.allocate( _size );
				for ( size_type i = 0; i < _size; i++ )
					alloc.construct(data + i, val);
			};

			//range constructor
			// vector( Iterator first, Iterator last );

			//copy constructor
			vector( const vector &source )
			{
				Allocator alloc;

				for ( size_type i = 0; i < _size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, _capacity );
				_size = source._size;
				_capacity = source._capacity;
				if ( _size > 0 )
					data = alloc.allocate( _capacity );
				for ( size_type i = 0; i < _size; i++ )
					alloc.construct( data + i, source.data[i] );
			};

			//copy assignement operator
			vector	&operator= ( const vector &source )
			{
				Allocator alloc;

				if ( this != &source )
				{
					for ( size_type i = 0; i < _size; i++ )
						alloc.destroy( data + i );
					alloc.deallocate( data, _capacity );
					_size = source._size;
					_capacity = source._capacity;
					if ( _size > 0 )
						data = alloc.allocate( _capacity );
					for ( size_type i = 0; i < _size; i++ )
						alloc.construct( data + i, source.data[i] );
				}
				return (*this);
			};

			//destructor
			~vector( void )
			{
				Allocator alloc;
				for ( size_type i = 0; i < _size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, _capacity );
				_size = 0;
			};

			//[] operator
			T	&operator[]( size_type index ) const
			{
				return (index >= _size) ? throw(std::out_of_range("error: out of range")) : data[index];
			};

			//at member function
			T	&at( size_type position ) const
			{
				return (position >= _size) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			
			//back memeber function
			T	&back( void ) const
			{
				return (_size > 0) ? data[_size - 1] : throw(std::out_of_range("error out of range"));
			};

			//empty member function
			bool	empty( void ) const
			{
				return (_size == 0) ? true : false;
			};

			//resize memeber function
			// void	resize( size_type newSize, const T &val )
			// {
			// 	Allocate alloc;

			// 	if ( newSize == 0 )
			// 		throw(std::runtime_error("error: size can't be zero"));
			// 	if ( newSize < size )
			// 	{
					
			// 	}
			// };

			//capacity member function
			size_type	capacity( void ) const
			{
				return (_capacity);
			};

			//size member function
			size_type	size( void ) const
			{
				return (_size);
			};

			//push_back member function
			void	push_back( const T &val )
			{
				if ( _size + 1 > _capacity )
				{
					_capacity += 3;
					T *newData = alloc.allocate(_capacity);
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size);
					data = newData;
				}
				_size += 1;
				data[_size - 1] = val;
			};
		private:
			T	*data;
			size_type	_size;
			size_type	_capacity;
			Allocator	alloc;
	};
}
