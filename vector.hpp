/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:42:13 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 11:59:27 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <cstddef>

typedef size_t size_type;
// typedef Allocator allocator_type;

namespace ft
{
	template< typename T, typename Allocator = std::allocator<T> >
	
	class vector
	{
		public:
			vector( void ) : data(NULL), size(0) {};
			// explicit vector( const Allocator &allocator );
			explicit vector( size_type size, const T &val ) : size(size)
			{
				Allocator alloc;

				data = alloc.allocate( size + 2 );
				for ( size_type i = 0; i < size; i++ )
					alloc.construct(data + i, val);
			};
			// vector( const vector &source );
		private:
			T	*data;
			size_type	size;
	};
}

