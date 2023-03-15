/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/15 14:59:01 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "fancy_tree.hpp"

int main( void )
{
	RedBlackTree<char, int> tree;
	node<char, int> *n1 = new node<char, int>( 'a', 1 );
	node<char, int> *n2 = new node<char, int>( 'b', 2 );
	node<char, int> *n3 = new node<char, int>( 'c', 2 );
	tree.insertNode(n1);
	tree.insertNode(n2);
	tree.insertNode(n3);
	// tree.print( tree.getRoot() );
	fancy_tree<char, int> tree2; 
	tree2.print_tree(tree.getRoot(), V_VIEW);
}