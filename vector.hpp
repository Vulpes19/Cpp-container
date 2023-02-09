/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/09 14:16:06 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "Iterator.hpp"


// typedef Allocator allocator_type;

namespace ft
{
	template< typename T, typename Allocator = std::allocator<T> >
	
	class vector
	{
		public:
			//alias
			typedef size_t size_type;
			typedef T* iterator;

			//default constructor
			vector( void ) : data(NULL), _size(0), _capacity(0) {};

			//fill constructor
			explicit vector( size_type size, const T &val ) : _size(size), _capacity(size)
			{
				if ( _size == 0 )
					throw(std::length_error("size can't be zero"));
				data = alloc.allocate( _size );
				if ( data == NULL )
						throw(std::length_error("maximum supported size is exceeded"));
				for ( size_type i = 0; i < _size; i++ )
					alloc.construct(data + i, val);
				_begin = data;
				_end = data + size - 1;
			};

			//range constructor
			// vector( Iterator first, Iterator last );

			//copy constructor
			vector( const vector &source )
			{
				for ( size_type i = 0; i < _size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, _capacity );
				_size = source._size;
				_capacity = source._capacity;
				if ( _size > 0 )
				{
					data = alloc.allocate( _capacity );
					if ( data == NULL )
						throw(std::length_error("maximum supported size is exceeded"));
				}
				for ( size_type i = 0; i < _size; i++ )
					alloc.construct( data + i, source.data[i] );
			};

			//copy assignement operator
			vector	&operator= ( const vector &source )
			{
				if ( this != &source )
				{
					for ( size_type i = 0; i < _size; i++ )
						alloc.destroy( data + i );
					alloc.deallocate( data, _capacity );
					_size = source._size;
					_capacity = source._capacity;
					if ( _size > 0 )
					{
						data = alloc.allocate( _capacity );
						if ( data == NULL )
							throw(std::length_error("maximum supported size is exceeded"));
					}
					for ( size_type i = 0; i < _size; i++ )
						alloc.construct( data + i, source.data[i] );
				}
				return (*this);
			};

			//destructor
			~vector( void )
			{
				for ( size_type i = 0; i < _size; i++ )
					alloc.destroy( data + i );
				alloc.deallocate( data, _capacity );
				_size = 0;
			};

			//[] operator
			T	&operator[]( size_type index )
			{
				return (index >= _size) ? throw(std::out_of_range("error: out of range")) : data[index];
			};

			const T	&operator[]( size_type index ) const
			{
				return (index >= _size) ? throw(std::out_of_range("error: out of range")) : data[index];
			};

			//swap member function

			void	swap( vector &x )
			{
				std::swap(data, x.data);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
			};

			/* iterators */
			//begin member function
			iterator	begin( void )
			{
				return (_begin);
			};

			//end member function
			iterator	end( void )
			{
				return (_end);
			};

			//operations
			//at member function
			T	&at( size_type position ) const
			{
				return (position >= _size) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			
			//front member function
			T	&front( void ) const
			{
				return (data[0]);
			};
	
			//back member function
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
			void	resize( size_type newSize, const T &val )
			{
				if ( newSize == 0 )
					throw(std::length_error("size can't be zero"));
				if ( newSize > _size )
				{
					_capacity = newSize;
					T *newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::length_error("maximum supported size is exceeded"));
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size);
					data = newData;
				}
				for ( size_t i = _size; i < newSize; i++ )
					data[i] = val;
				_size = newSize;
			};

			//reserve member function
			void	reserve( size_type newSize )
			{
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					T *newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::length_error("maximum supported size is exceeded"));
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size);
					data = newData;
				}
			};

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
					if ( newData == NULL )
						throw(std::length_error("maximum supported size is exceeded"));
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

			//pop_back member function
			void	pop_back( void )
			{
				if ( _size == 0 )
					throw(std::length_error("size is zero"));
				_size -= 1;
				alloc.destroy( data + _size );
			};

			//clear member function
			void	clear( void )
			{
				for ( size_type i = 0; i < _size; i++ )
					alloc.destroy(data + i);
				_size = 0;
			};

			//get_allocator member function
			Allocator	get_allocator( void ) const
			{
				return (alloc);
			};

			size_type	max_size( void ) const
			{
				return (alloc.max_size());
			};
		private:
			T			*data;
			iterator	_begin;
			iterator	_end;
			size_type	_size;
			size_type	_capacity;
			Allocator	alloc;
	};
}
