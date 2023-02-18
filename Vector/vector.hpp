/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/18 19:02:24 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "../Iterators/Iterator.hpp"
#include "../Iterators/Iterator_traits.hpp"
#include "../TypeTraits/TypeTraits.hpp"
#include "../Algorithm/Algorithm.hpp"
#include <iterator>

namespace ft
{
	template< typename T, typename Allocator = std::allocator<T> >
	
	class vector
	{
		public:
			//alias
			typedef size_t size_type;
			typedef T value_type;
			typedef value_type& reference;
			typedef Allocator allocator_type;
			// typedef const typename reference const_reference;
			typedef random_access_iterator< T > iterator;
			typedef random_access_iterator< const T > const_iterator;
			typedef reverse_iterator< iterator > reverse_iterator;

			//default constructor
			explicit vector( const allocator_type &alloc = allocator_type() ) : data(NULL), _size(0), _capacity(0), alloc(alloc) {};
			//fill constructor
			explicit vector( size_type size, const T &val ) : _size(size), _capacity(size)
			{
				if ( _size == 0 )
				{
					data = NULL;
					return ;
				}
				data = alloc.allocate( _capacity );
				if ( data == NULL )
						throw(std::bad_alloc());
				for ( size_type i = 0; i < _size; i++ )
					alloc.construct(data + i, val);
			};

			// range constructor
			template< typename InputIterator >
			vector( typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type() ) : alloc(alloc)
			{
				size_type newSize = ft::distance(first, last);
				if ( newSize == 0 )
				{
					data = NULL;
					_size = 0;
					return ;
				}
				_capacity = newSize;
				data = alloc.allocate( _capacity );
				if ( data == NULL )
					throw(std::bad_alloc());
				for ( size_type i = 0; first != last; i++, first++ )
					alloc.construct(data + i, *first);
			};

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
			reference	operator[]( size_type index )
			{
				return (index >= _size) ? throw(std::out_of_range("error: out of range")) : data[index];
			};

			reference operator[]( size_type index ) const
			{
				return (index >= _size) ? throw(std::out_of_range("error: out of range")) : data[index];
			};

			//swap member function

			void	swap( vector &x )
			{
				ft::swap(data, x.data);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
			};

			/* iterators */
			//begin member function
			iterator	begin( void )
			{
				return (iterator( data ));
			};

			const_iterator	begin( void ) const
			{
				return (iterator( data ));
			};

			reverse_iterator	rbegin( void )
			{
				return (iterator( data + _size));
			};

			//end member function
			iterator	end( void )
			{
				return (iterator( data + _size ));
			};

			const_iterator	end( void ) const
			{
				return (iterator( data + _size ));
			};

			reverse_iterator	rend( void )
			{
				return (iterator( data ));
			};

			//assign member function
			void	assign( size_type newSize, const value_type value )
			{
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					value_type *newData = alloc.allocate(_capacity);
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
				for ( size_type i = 0; i < newSize; i++ )
					alloc.construct( data + i, value);
				for ( size_type i = newSize; i < _size; i++ )
					alloc.destroy(data + i);
				_size = newSize;
			};
			
			template< typename InputIterator >

			void	assign( typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last )
			{
				size_type newSize = ft::distance(first, last);
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					value_type *newData = alloc.allocate(_capacity);
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
				size_type i = 0;
				for ( ; first != last; ++first, i++ )
				{
					alloc.construct(data + i, *(first));
				}
				for ( int j = i; i < _size; i++ )
					alloc.destroy(data + j);
				_size = newSize;
			};

			//insert member function
			iterator	insert( iterator position, const value_type &value )
			{
				size_type index = position - data;
				_size += 1;

				if ( _size > _capacity )
				{
					size_type i, j;
					
					i = 0;
					j = 0;
					_capacity *= 2;
					value_type	*newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					while ( i < _size && j < _size - 1 )
					{
						if ( i == index )
						{
							alloc.construct(newData + i, value);
							i++;
							continue ;
						}
						alloc.construct(newData + i, data[j]);
						alloc.destroy(data + j);
						i++;
						j++;
					}
					alloc.deallocate(data, _size - 1);
					data = newData;
				}
				else
				{
					for ( size_type i = _size; i > index; --i )
					{
						data[i] = data[i - 1];
					}
					data[index] = value;
				}
				return ( position );
			};

			void	insert( iterator position, size_type n, const value_type &value )
			{
				size_type index = position - data;
				if ( _size + n > _capacity )
				{
					size_type i, j;
					
					i = 0;
					j = 0;
					_capacity *= 2;
					value_type	*newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					while ( i < _size + n && j < _size )
					{
						if ( i == index )
						{
							for ( size_type k = i; k < i + n; k++ )
								alloc.construct(newData + k, value);
							i += n;
							continue ;
						}
						alloc.construct(newData + i, data[j]);
						alloc.destroy(data + j);
						i++;
						j++;
					}
					alloc.deallocate(data, _size);
					_size += n;
					data = newData;
				}
				else
				{
					for ( size_type i = _size - 1; i > index; --i )
						data[i + n] = data[i];
					for ( size_type i = index; i < index + n; i++ )
						data[i] = value;
					_size += n;
				}
			};

			template < typename InputIterator >
			
			void	insert( typename ft::enable_if<!ft::is_integral<InputIterator>::value, typename ft::vector<T>::iterator>::type position,
				 InputIterator first, InputIterator last )
			{
				size_type	index = position - data;
				size_type	n = ft::distance( first, last );
				if ( _size + n > _capacity )
				{
					size_type i, j;
					
					i = 0;
					j = 0;
					_capacity *= 2;
					value_type	*newData = alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					while ( i < _size + n && j < _size )
					{
						if ( i == index )
						{
							for ( size_type k = i; first != last; k++, ++first )
								alloc.construct(newData + k, *first);
							i += n;
							continue ;
						}
						alloc.construct(newData + i, data[j]);
						alloc.destroy(data + j);
						i++;
						j++;
					}
					alloc.deallocate(data, _size);
					_size += n;
					data = newData;
				}
			};
			//erase member function
			iterator	erase( iterator position )
			{
				size_type index = position - data;
				size_type i = 0;
				size_type j = 0;
				value_type *newData = alloc.allocate(_capacity);
				if ( newData == NULL )
					throw(std::bad_alloc());
				while ( i < _size && j < _size - 1 )
				{
					if ( index == i )
					{
						i++;
						continue ;
					}
					alloc.construct(newData + j, data[i]);
					alloc.destroy(data + i);
					i++;
					j++;
				}
				alloc.deallocate(data, _size);
				_size -= 1;
				data = newData;
				return (position);
			}

			iterator	erase( iterator first, iterator last )
			{
				if ( first > data )
					first = data;
				size_type start = first - data;
				size_type end = last - data;
				size_type n = last - first;
				size_type i = 0;
				size_type j = 0;
				value_type *newData = alloc.allocate(_capacity);
				if ( newData == NULL )
					throw(std::bad_alloc());
				while ( i < _size && j < _size - n )
				{
					if ( start == i )
					{
						while ( i < end )
							i++;
						continue ;
					}
					alloc.construct(newData + j, data[i]);
					alloc.destroy(data + i);
					i++;
					j++;
				}
				alloc.deallocate(data, _size);
				_size -= n;
				data = newData;
				return (first);
			}
			//operations
			//at member function
			reference	at( size_type position )
			{
				return (position >= _size) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			
			reference	at( size_type position ) const
			{
				return (position >= _size) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			//front member function
			reference	front( void )
			{
				return (data[0]);
			};

			reference	front( void ) const
			{
				return (data[0]);
			};
			//back member function
			reference	back( void )
			{
				return (_size > 0) ? data[_size - 1] : throw(std::out_of_range("error out of range"));
			};
			
			reference	back( void ) const
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
					value_type *newData = alloc.allocate(_capacity);
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
				for ( size_type i = _size; i < newSize; i++ )
					data[i] = val;
				_size = newSize;
			};

			//reserve member function
			void	reserve( size_type newSize )
			{
				if ( newSize > _capacity )
				{
					_capacity = newSize;
					value_type *newData = alloc.allocate(_capacity);
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
					_capacity *= 2;
					if ( _capacity == 0 )
						_capacity = 1;
					value_type *newData = alloc.allocate(_capacity);
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
				if ( _size < _capacity / 2 )
				{
					_capacity = _size;
					value_type *newData = alloc.allocate( _capacity );
					if ( newData == NULL )
						throw( std::bad_alloc() );
					for ( size_type i = 0; i < _size; i++ )
					{
						alloc.construct(newData + i, data[i]);
						alloc.destroy(data + i);
					}
					alloc.deallocate(data, _size + 1);
					data = newData;
				}
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
