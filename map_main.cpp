/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/17 16:21:50 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "fancy_tree.hpp"

int main( void )
{
	RedBlackTree<int, int> *tree = new RedBlackTree<int, int>();
	node<int, int> *n1 = new node<int, int>( 1, 1 );
	node<int, int> *n2 = new node<int, int>( 2, 2 );
	node<int, int> *n3 = new node<int, int>( 3, 2 );
	node<int, int> *n4 = new node<int, int>( 4, 4 );
	node<int, int> *n5 = new node<int, int>( 5, -2 );
	fancy_tree<int, int> tree2; 
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
	tree->deleteNode(n4);
	tree2.print_tree(tree->getRoot(), V_VIEW);
	tree->deleteNode(n5);
	tree->draw();
	// system("leaks test_map");
	// tree.print( tree.getRoot() );
}