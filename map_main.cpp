/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/15 12:16:31 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

int main( void )
{
    RedBlackTree<int, char> tree;
    node<int, char> *n1 = new node<int, char>( 1, 'a' );
    node<int, char> *n2 = new node<int, char>( 2, 'b' );
    node<int, char> *n3 = new node<int, char>( 3, 'c' );
    tree.insertNode(n1);
    tree.insertNode(n2);
    tree.insertNode(n3);
    tree.print( tree.getRoot() );
}