/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:28:55 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/17 16:43:32 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Iterator_traits.hpp"
#include "../TypeTraits/TypeTraits.hpp"
#include "../Map/RedBlackTree.hpp"

namespace ft
{
    template < typename Key, typename T >
    
    class bidirectional_iterator
    {
        public:
            typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T*						const_pointer;
			typedef const T& 						const_reference;
			typedef	std::bidirectional_iterator_tag iterator_category;
			typedef size_t 							size_type;
        private:
            node<Key, T> *n;
    };
}