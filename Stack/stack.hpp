/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:49:38 by codespace         #+#    #+#             */
/*   Updated: 2023/03/11 11:20:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector/vector.hpp"

namespace ft
{
    template < typename T, typename Container = ft::vector<T> >

    class stack
    {
        public:
            typedef T   value_type;
            typedef Container container_type;
            typedef typename Container::size_type size_type;
            typedef typename Container::reference reference;
            typedef typename Container::const_reference const_reference;

            explicit stack( const container_type &ctnr = container_type() )
            {
                container = ctnr;
            };
            
            bool empty( void ) const
            {
                return (container.empty());
            };

            void    pop( void )
            {
                container.pop_back();
            };

            void    push( const value_type &val )
            {
                container.push_back(val);
            };

            size_type   size( void ) const
            {
                return (container.size());
            };

            value_type  &top( void )
            {
                return (container.back());
            };

            const value_type  &top( void ) const
            {
                return (container.back());
            };

            template < typename U, typename cntr >
            friend bool operator==( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container == st2.container );
            };

            template < typename U, typename cntr >
            friend bool operator!=( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container != st2.container );
            };

            template < typename U, typename cntr >
            friend bool operator<( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container < st2.container );
            };

            template < typename U, typename cntr >
            friend bool operator<=( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container <= st2.container );
            };

            template < typename U, typename cntr >
            friend bool operator>( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container > st2.container );
            };

            template < typename U, typename cntr >
            friend bool operator>=( const stack<U, cntr> &st1, const stack<U, cntr> &st2 )
            {
                return ( st1.container >= st2.container );
            };
        private:
            container_type container;
    };
}