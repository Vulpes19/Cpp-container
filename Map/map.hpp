/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:32 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/15 10:02:35 by abaioumy         ###   ########.fr       */
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
			typedef Key										key_type;
			typedef T   									mapped_type;
			typedef ft::pair< const key_type, mapped_type > value_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
		private:
		
	};
}