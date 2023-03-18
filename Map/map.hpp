/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:32 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/18 17:44:41 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "../Iterators/Iterator_traits.hpp"
#include "../TypeTraits/TypeTraits.hpp"
#include "../Algorithm/Algorithm.hpp"
#include "../Utility/utility.hpp"
#include "RedBlackTree.hpp"
#include <limits>

namespace ft
{
	template<   typename Key,
				typename T, 
				typename Compare = std::less<Key>, 
				typename Allocator = std::allocator< ft::pair< const Key, T> >
			> 
	class map
	{
		public:
			typedef Key														key_type;
			typedef T   													mapped_type;
			typedef ft::pair< const key_type, mapped_type > 				value_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef value_type&												reference;
			typedef const value_type&										const_reference;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t 													size_type;

			explicit map( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {};
			template < typename InputIterator >
			map( InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() ) {};
			map( const map &x );
			//begin
			// iterator begin( void );
			// const_iterator	begin( void ) const;
			//end
			// iterator end( void );
			// const_iterator	end( void ) const;
			//clear
			// void	clear( void );
			//count
			// size_type	count( const key_type &k ) const;
			//empty
			bool	empty( void ) const
			{
				return ( _size == 0 );
			};
			
			//equal range
			// ft::pair< const_iterator, const_iterator > equal_range( const key_type &k ) const {};
			
		private:
			size_type	_size;
			Compare		_comp;
			Allocator	_alloc;
			RedBlackTree< value_type, Compare, Allocator > tree;	
	};
}