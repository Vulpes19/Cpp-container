/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/02 12:14:51 by abaioumy         ###   ########.fr       */
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
			typedef Allocator allocator_type;
			typedef T value_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer	pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef ft::random_access_iterator< T > iterator;
			typedef ft::reverse_iterator< iterator > reverse_iterator;
			typedef ft::random_access_iterator< const T > const_iterator;
			typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

			//default constructor
			explicit vector( const allocator_type &alloc = allocator_type() ) : data(NULL), _size(0), _capacity(0), _alloc(alloc) {};
			//fill constructor
			explicit vector( size_type size, const T &val = value_type() ) : _size(size), _capacity(size)
			{
				if ( _size == 0 )
				{
					data = NULL;
					return ;
				}
				data = _alloc.allocate( _capacity );
				if ( data == NULL )
						throw(std::bad_alloc());
				for ( size_type i = 0; i < _size; i++ )
					_alloc.construct(data + i, val);
			};

			template< typename InputIterator >

			void	copying( InputIterator first, InputIterator last, std::input_iterator_tag )
			{
				_size = 0;
				_capacity = 0;
				for ( ; first != last; ++first )
				{
					push_back(*first);
				}
			}

			template< typename InputIterator >

			void	copying( InputIterator first, InputIterator last, std::forward_iterator_tag )
			{
				_size = 0;
				_capacity = 0;
				for ( ; first != last; ++first )
				{
					push_back(*first);
				}
			}

			template< typename InputIterator >

			void	copying( InputIterator first, InputIterator last, ft::random_access_iterator_tag )
			{
				size_type newSize = ft::distance(first, last);
				_capacity = newSize;
				_size = newSize;
				data = _alloc.allocate( _capacity );
				if ( data == NULL )
					throw(std::bad_alloc());
				for ( size_type i = 0; first != last; i++, ++first ) 
					_alloc.construct(data + i, *first);
			}

			template< typename InputIterator >

			void	copying( InputIterator first, InputIterator last, std::random_access_iterator_tag )
			{
				size_type newSize = ft::distance(first, last);
				_capacity = newSize;
				_size = newSize;
				data = _alloc.allocate( _capacity );
				if ( data == NULL )
					throw(std::bad_alloc());
				for ( size_type i = 0; first != last; i++, ++first ) 
					_alloc.construct(data + i, *first);
			}

			// range constructor
			template< typename InputIterator >

			vector( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type() ) : _alloc(alloc)
			{
				copying( first, last, typename ft::iterator_traits<InputIterator>::iterator_category() );
			};

			//copy constructor
			vector( const vector &source )
			{
				_size = source._size;
				_capacity = source._capacity;
				data = _alloc.allocate( _capacity );
				for ( size_type i = 0; i < _size; i++ )
					_alloc.construct( data + i, source.data[i] );
			};

			//copy assignement operator
			vector	&operator= ( const vector &source )
			{
				if ( this != &source )
				{
					for ( size_type i = 0; i < _size; i++ )
						_alloc.destroy( data + i );
					if ( data )
						_alloc.deallocate( data, _capacity );
					_size = source._size;
					_capacity = source._capacity;
					if ( _size > 0 )
						data = _alloc.allocate( _capacity );
					for ( size_type i = 0; i < _size; i++ )
						_alloc.construct( data + i, source.data[i] );
				}
				return (*this);
			};

			//destructor
			~vector( void )
			{
				if ( _capacity == 0 )
					return ;
				for ( size_type i = 0; i < _size; i++ )
					_alloc.destroy( data + i );
				if ( data )
					_alloc.deallocate( data, _capacity );
				_size = 0;
				_capacity = 0;
			};

			//[] operator
			reference	operator[]( size_type index )
			{
				return (index >= _size) ? throw(std::invalid_argument("invalid range")) : data[index];
			};

			const_reference operator[]( size_type index ) const
			{
				return (index >= _size) ? throw(std::invalid_argument("invalid range")) : data[index];
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
				return (const_iterator( data ));
			};

			reverse_iterator	rbegin( void )
			{
				return (reverse_iterator(data + _size));
			};

			//end member function
			iterator	end( void )
			{
				return (iterator( data + _size ));
			};

			const_iterator	end( void ) const
			{
				return (const_iterator( data + _size ));
			};

			reverse_iterator	rend( void )
			{
				return (reverse_iterator( data ));
			};

			//assign member function
			void	assign( size_type newSize, const value_type &value )
			{
				if ( newSize > _capacity )
				{
					size_type tmpCapacity = _capacity;
					if ( _capacity < newSize )
						_capacity = newSize;
					else
						_capacity *= 2;
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.destroy(data + i);
					}
					if ( data )
						_alloc.deallocate(data, tmpCapacity);
					_size = newSize;
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.construct(newData + i, value);
					}
					data = newData;
				}
				else
				{
					for ( size_type i = 0; i < newSize; i++ )
					{
						if ( i >= _size )
							_alloc.construct(data + i, value);
						else
						{
							_alloc.destroy( data + i );
							_alloc.construct(data + i, value);
						}
					}
					if ( _size >= newSize )
					{
						for ( size_type i = newSize; i < _size; i++ )
							_alloc.destroy( data + i );
					}
					_size = newSize;
				}
			};
			
			//assign range member function
			template< typename InputIterator >

			void	assigning( InputIterator first, InputIterator last, std::input_iterator_tag )
			{
				clear();
				for ( ; first != last; ++first )
				{
					push_back(*first);
				}
			}

			template< typename InputIterator >

			void	assigning( InputIterator first, InputIterator last, std::forward_iterator_tag )
			{
				clear();
				for ( ; first != last; ++first )
				{
					push_back(*first);
				}
			}

			template< typename InputIterator >

			void	assigning( InputIterator first, InputIterator last, ft::random_access_iterator_tag )
			{
				size_type newSize = ft::distance(first, last);
				if ( newSize > _capacity )
				{
					if ( _capacity < newSize )
						_capacity = newSize;
					else
						_capacity *= 2;
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					if ( data )
					{
						for ( size_type i = 0; i < _size; i++ )
							_alloc.destroy(data + i);
						_alloc.deallocate(data, _size);
					}
					_size = newSize;
					for ( size_type i = 0; first != last; i++, ++first )
					{
						_alloc.construct(newData + i, *(first) );
					}
					data = newData;
					_size = newSize;
					return ;
				}
				else
				{
					for ( size_type i = 0; first != last; i++, ++first )
					{
						if ( i >= _size )
							_alloc.construct(data + i, *(first));
						else
						{
							_alloc.destroy( data + i );
							_alloc.construct(data + i, *(first));
						}
					}
					if ( _size > newSize )
					{
						for ( size_type i = newSize; i < _size; i++ )
							_alloc.destroy( data + i );
					}
					_size = newSize;
				}
			}

			template< typename InputIterator >

			void	assigning( InputIterator first, InputIterator last, std::random_access_iterator_tag )
			{
				size_type newSize = ft::distance(first, last);
				if ( newSize > _capacity )
				{
					if ( _capacity < newSize )
						_capacity = newSize;
					else
						_capacity *= 2;
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					if ( data )
					{
						for ( size_type i = 0; i < _size; i++ )
							_alloc.destroy(data + i);
						_alloc.deallocate(data, _size);
					}
					_size = newSize;
					for ( size_type i = 0; first != last; i++, ++first )
					{
						_alloc.construct(newData + i, *(first) );
					}
					data = newData;
					_size = newSize;
					return ;
				}
				else
				{
					for ( size_type i = 0; first != last; i++, ++first )
					{
						if ( i >= _size )
							_alloc.construct(data + i, *(first));
						else
						{
							_alloc.destroy( data + i );
							_alloc.construct(data + i, *(first));
						}
					}
					if ( _size > newSize )
					{
						for ( size_type i = newSize; i < _size; i++ )
							_alloc.destroy( data + i );
					}
					_size = newSize;
				}
			}

			template< typename InputIterator >

			void	assign( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last )
			{
				assigning( first, last, typename ft::iterator_traits<InputIterator>::iterator_category() );
			};

			//insert member function
			iterator	insert( iterator position, const value_type &value )
			{
				if ( position > end() )
					return (position);
				if ( position == end() )
				{
					push_back(value);
					return (end() - 1);
				} 
				if ( _size == 0 )
				{
					push_back(value);
					return (begin());
				}
				size_type index = position - begin();
				if ( _size + 1 > _capacity )
				{
					_size += 1;
					size_type i, j;
					
					i = 0;
					j = 0;
					size_type tmp = _capacity;
					_capacity *= 2;
					value_type	*newData = _alloc.allocate(_capacity);
					while ( i < _size && j < _size - 1 )
					{
						if ( i == index )
						{
							_alloc.construct(newData + i, value);
							i++;
						}
						else
						{
							_alloc.construct(newData + i, data[j]);
							_alloc.destroy(data + j);
							i++;
							j++;
						}
					}
					if (data )
						_alloc.deallocate(data, tmp);
					data = newData;
				}
				else
				{
					for ( size_type i = _size; i > index; --i )
					{
						if ( i == _size )
							_alloc.construct( data + i, data[i - 1] );
						else
							data[i] = data[i - 1];
					}
					_size += 1;
					data[index] = value;
				}
				return ( begin() + index );
			};

			void	insert( iterator position, size_type n, const value_type &value )
			{
			
				if ( _size == 0 || position == end() )
				{
					for ( size_type i = 0; i < n; i++ )
						push_back(value);
					return ;
				}
				size_type index = position - data;
				if ( _size + n > _capacity )
				{
					size_type i, j;
					
					i = 0;
					j = 0;
					_capacity *= 2;
					value_type	*newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					while ( i < _size + n && j < _size )
					{
						if ( i == index )
						{
							for ( size_type k = i; k < i + n; k++ )
								_alloc.construct(newData + k, value);
							i += n;
							continue ;
						}
						_alloc.construct(newData + i, data[j]);
						// std::cout << "destoryed: " << j << std::endl;
						_alloc.destroy(data + j);
						i++;
						j++;
					}
					if (data)
						_alloc.deallocate(data, _capacity);
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
					value_type	*newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					while ( i < _size + n && j < _size )
					{
						if ( i == index )
						{
							for ( size_type k = i; first != last; k++, ++first )
								_alloc.construct(newData + k, *first);
							i += n;
							continue ;
						}
						_alloc.construct(newData + i, data[j]);
						_alloc.destroy(data + j);
						i++;
						j++;
					}
					_alloc.deallocate(data, _size);
					_size += n;
					data = newData;
				}
			};
			//erase member function
			iterator	erase( iterator position )
			{
				size_type index = position - data;
				size_type i = index;
				bool	destroyed = false;
		
				if ( index >= _size )
					return (end());
				if ( index == _size - 1 )
				{
					destroyed = true;
					_alloc.destroy(data + index);
				}
				else
				{
					while ( i < _size )
					{
						if ( i + 1 >= _size)
							break ;
						value_type tmp = data[i + 1];
						_alloc.destroy( data + i + 1);
						if ( index == i )
						{
							_alloc.destroy(data + i);
							_alloc.construct( data + i, tmp);
							destroyed = true;
						}
						else
							_alloc.construct( data + i, tmp );
						i++;
					}
				}
				if ( !destroyed )
					_alloc.destroy( data + index );
				_size -= 1;
				if ( _size == 0 ) return (begin());
				if ( index == _size ) return ( position );
				return ( position );
			}

			iterator	erase( iterator first, iterator last )
			{
				// if ( first >= data + _size || first < data || first >= last  || last >= data + _size )
				// 	return (first);
				size_type start = first - data;
				size_type finish = last - data;
				if ( start >= _size || start >= finish || finish > _size )
					return (first);
				size_type n = last - first;
				if ( start == 0 && finish == _size )
				{
					for ( size_type i = 0; i < _size; i++ )
						_alloc.destroy(data + i);
					_size = 0;
					return end();
				}
				size_type i = 0;
				size_type j = 0;
				value_type *newData = _alloc.allocate(_capacity);
				while ( i < _size && j < _size - n )
				{
					if ( start == i )
					{
						while ( i < finish )
						{
							_alloc.destroy( data + i );
							i++;
						}
						continue ;
					}
					_alloc.construct(newData + j, data[i]);
					_alloc.destroy(data + i);
					i++;
					j++;
				}
				_alloc.deallocate(data, _capacity);
				_size -= n;
				data = newData;
				return (first + n);
			}
			//operations
			//at member function
			reference	at( size_type position )
			{
				return ( position >= _size ) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			
			const_reference	at( size_type position ) const
			{
				return ( position >= _size ) ? throw(std::out_of_range("error: out of range")) : data[position];
			};
			//front member function
			reference	front( void )
			{
				return (data[0]);
			};

			const_reference	front( void ) const
			{
				return (data[0]);
			};
			//back member function
			reference	back( void )
			{
				return (_size > 0) ? data[_size - 1] : throw(std::out_of_range("error out of range"));
			};
			
			const_reference	back( void ) const
			{
				return (_size > 0) ? data[_size - 1] : throw(std::out_of_range("error out of range"));
			};
			//empty member function
			bool	empty( void ) const
			{
				return ( _size == 0 );
			};

			//resize memeber function
			void	resize( size_type newSize, value_type val = value_type() )
			{
				if ( newSize == 0 )
				{
					for ( size_type i = 0; i < _size; i++ )
						_alloc.destroy(data + i);
					_size = 0;
					return ;
				}
				if ( newSize > _capacity )
				{
					_capacity *= 2;
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.construct(newData + i, data[i]);
						_alloc.destroy(data + i);
					}
					_alloc.deallocate(data, _size);
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
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.construct(newData + i, data[i]);
						_alloc.destroy(data + i);
					}
					_alloc.deallocate(data, _size);
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
				if ( _capacity == 0 )
				{
					_capacity = 1;
					data = _alloc.allocate(_capacity);
					_alloc.construct( data, val );
					_size = 1;
					return ;
				}
				if ( _size + 1 > _capacity )
				{
					_capacity *= 2;
					value_type *newData = _alloc.allocate(_capacity);
					if ( newData == NULL )
						throw(std::bad_alloc());
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.construct(newData + i, data[i]);
						_alloc.destroy(data + i);
					}
					if (data)
						_alloc.deallocate(data, _size);
					data = newData;
				}
				_alloc.construct( data + _size, val );
				_size += 1;
			};

			//pop_back member function
			void	pop_back( void )
			{
				// if ( _size == 0 )
				// 	throw(std::length_error("size is zero"));
				_size -= 1;
				_alloc.destroy( data + _size - 1 );
				if ( _size < _capacity / 2 )
				{
					_capacity = _size;
					value_type *newData = _alloc.allocate( _capacity );
					// if ( newData == NULL )
					// 	throw( std::bad_alloc() );
					for ( size_type i = 0; i < _size; i++ )
					{
						_alloc.construct(newData + i, data[i]);
						_alloc.destroy(data + i);
					}
					_alloc.deallocate(data, _size + 1);
					data = newData;
				}
			};

			//clear member function
			void	clear( void )
			{
				for ( size_type i = 0; i < _size; i++ )
						_alloc.destroy(data + i);
				_size = 0;
			};

			//get_allocator member function
			Allocator	get_allocator( void ) const
			{
				return (_alloc);
			};

			size_type	max_size( void ) const
			{
				return (_alloc.max_size());
			};

			template< typename U, typename Alloc >

			friend bool operator==( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );

			template< typename U, typename Alloc >

			friend bool operator!=( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );

			template< typename U, typename Alloc >

			friend bool operator<=( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );

			template< typename U, typename Alloc >

			friend bool operator>=( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );

			template< typename U, typename Alloc >

			friend bool operator<( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );

			template< typename U, typename Alloc >

			friend bool operator>( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 );
		private:
			T			*data;
			size_type	_size;
			size_type	_capacity;
			Allocator	_alloc;
	};

	template< typename T, typename Alloc >

	bool operator==( const vector<T, Alloc> &v1, const vector<T, Alloc> &v2 )
	{
		if ( v1._size == v2._size)
		{
			for ( size_t i = 0; i < v1._size; i++ )
			{
				if ( v1[i] != v2[i] )
					return (false);
			}
			return (true);
		}
		else
			return (false);
	}

	template< typename T, typename Alloc >

	bool operator!=( const vector<T, Alloc> &v1, const vector<T, Alloc> &v2 )
	{
		if ( v1._size == v2._size)
		{
			for ( size_t i = 0; i < v1._size; i++ )
			{
				if ( v1[i] != v2[i] )
					return (true);
			}
			return (false);
		}
		else
			return (true);
	}

	template< typename U, typename Alloc >

	bool operator<( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 )
	{
		if ( v1._size < v2._size )
			return (true);
		if ( v1._size > v2._size )
			return (false);
		size_t i = 0;
		while ( i < v1._size && i < v2._size )
		{
			if ( v1[i] < v2[i] )
				return (true);
			i++;
		}
		return (false);
	}

	template< typename U, typename Alloc >

	bool operator<=( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 )
	{
		if ( v1 == v2 || v1._size < v2._size )
			return (true);
		if ( v1._size > v2._size )
			return (false);
		size_t i = 0;
		while ( i < v1._size && i < v2._size )
		{
			if ( v1[i] <= v2[i] )
				return (true);
			i++;
		}
		return (false);
	}

	template< typename U, typename Alloc >

	bool operator>( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 )
	{
		if ( v1._size > v2._size )
			return (true);
		if ( v1._size < v2._size )
			return (false);
		size_t i = 0;
		while ( i < v1._size && i < v2._size )
		{
			if ( v1[i] > v2[i] )
				return (true);
			i++;
		}
		return (false);
	}

	template< typename U, typename Alloc >

	bool operator>=( const vector<U, Alloc> &v1, const vector<U, Alloc> &v2 )
	{
		if ( v1 == v2 || v1._size > v2._size )
			return (true);
		if ( v1._size < v2._size )
			return (false);
		size_t i = 0;
		while ( i < v1._size && i < v2._size )
		{
			if ( v1[i] >= v2[i] )
				return (true);
			i++;
		}
		return (false);
	}

	template< typename U, typename Alloc >

	void	swap( vector<U, Alloc> &x, vector<U, Alloc> &y )
	{
		x.swap(y);
	}
}
