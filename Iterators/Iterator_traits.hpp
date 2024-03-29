/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:59:49 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/20 13:06:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>

namespace ft
{
	
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct  random_access_iterator_tag: bidirectional_iterator_tag {};

	template< typename Iterator >
	class iterator_traits
	{
		public:
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template< typename T >
	class iterator_traits<T *>
	{
		public:
		typedef ptrdiff_t   difference_type;
		typedef T           value_type;
		typedef T*          pointer;
		typedef T&          reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};

	template< typename T >
	class iterator_traits< const T *>
	{
		public:
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*				pointer;
		typedef const T&				reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	};

}