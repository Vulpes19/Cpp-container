/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/16 14:09:53 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "fancy_tree.hpp"

int main( void )
{
	RedBlackTree<char, int> *tree = new RedBlackTree<char, int>();
	node<char, int> *n1 = new node<char, int>( 'c', 1 );
	node<char, int> *n2 = new node<char, int>( 'b', 2 );
	node<char, int> *n3 = new node<char, int>( 'a', 2 );
	node<char, int> *n4 = new node<char, int>( 'k', 4 );
	node<char, int> *n5 = new node<char, int>( 'e', -2 );
	fancy_tree<char, int> tree2; 
	tree->insertNode(n1);
	tree->insertNode(n2);
	tree2.print_tree(tree->getRoot(), V_VIEW);
	tree->insertNode(n3);
	std::cout << "*******\n";
	tree2.print_tree(tree->getRoot(), V_VIEW);
	tree->insertNode(n4);
	tree2.print_tree(tree->getRoot(), V_VIEW);

	tree->insertNode(n5);
	tree2.print_tree(tree->getRoot(), V_VIEW);
	// tree.print( tree.getRoot() );
}