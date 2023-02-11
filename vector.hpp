/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/11 15:51:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
			typedef T value_type;
			typedef random_access_iterator< vector<T> > iterator;

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
				return (iterator( data ));
			};

			//end member function
			iterator	end( void )
			{
				return (iterator( data + _size ));
			};

			void	assign( const iterator first, const iterator last )
			{
				size_t newSize = last - first;
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					T *newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size);
					_size = newSize;
					data = newData;
				}
				else
				{
					for ( size_type i = 0; i < _size; i++ )
						alloc.destroy(data + i);
				}
				size_t i = 0;
				iterator it = first;
				while ( i < _size && it < last )
				{
					data[i++] = *it;
					it++;
				}
				_size = newSize;
			};
			void	assign( size_type newSize, const value_type value )
			{
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					T *newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size);
					_size = newSize;
					data = newData;
				}
				else
				{
					for ( size_type i = 0; i < _size; i++ )
						alloc.destroy(data + i);
				}
				for ( size_t i = 0; i < newSize; i++ )
					data[i] = value;
				_size = newSize;
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
						throw(std::bad_alloc());
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
						throw(std::bad_alloc());
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
			size_type	_size;
			size_type	_capacity;
			Allocator	alloc;
	};
}
