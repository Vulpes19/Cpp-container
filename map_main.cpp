/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/18 19:07:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "Utility/Utility.hpp"
#include "fancy_tree.hpp"

typedef int			type;
typedef ft::pair<type, type> pair;
typedef std::allocator<pair> alloc;

int main( void )
{
	RedBlackTree<pair , alloc > *tree = new RedBlackTree<pair , alloc >();
	node<pair, alloc> *n1 = new node<pair, alloc>( 1, 1 );
	node<pair, alloc> *n2 = new node<pair, alloc>( 2, 2 );
	node<pair, alloc> *n3 = new node<pair, alloc>( 3, 2 );
	node<pair, alloc> *n4 = new node<pair, alloc>( 4, 4 );
	node<pair, alloc> *n5 = new node<pair, alloc>( 5, -2 );
	node<pair, alloc> *n6 = new node<pair, alloc>( 6, 4 );
	node<pair, alloc> *n7 = new node<pair, alloc>( 7, -2 );
	// fancy_tree<int, int> tree2; 
	tree->insertNode(n1);
	tree->insertNode(n2);
	// tree2.print_tree(tree->getRoot(), V_VIEW);
	tree->insertNode(n3);
	// std::cout << "*******\n";
	// tree2.print_tree(tree->getRoot(), V_VIEW);
	tree->insertNode(n4);
	// tree2.print_tree(tree->getRoot(), V_VIEW);

	tree->insertNode(n5);
	tree->insertNode(n6);
	tree->insertNode(n7);
	// tree2.print_tree(tree->getRoot(), V_VIEW);

	// tree2.print_tree(tree->getRoot(), V_VIEW);
	// tree->deleteNode(n4);
	// tree2.print_tree(tree->getRoot(), V_VIEW);
	// tree->deleteNode(n5);
	tree->draw();
	// system("leaks test_map");
	// tree.print( tree.getRoot() );
}