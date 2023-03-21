/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:51 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/21 16:23:14 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "Utility/Utility.hpp"
#include <vector>
#include <cstdlib>

typedef int			type;
typedef ft::pair<type, type> pair;
typedef std::allocator<pair> alloc;
typedef node<pair> node_pair;

int main( void )
{
	pair a(1, 1);
	pair b(2, 2);
	pair d(3, 2);
	pair c(4, 4);
	pair e(5, -2);
	pair f(6, 4);
	pair g(7, -2);
	RedBlackTree<pair ,std::less<pair::first_type>, alloc > *tree = new RedBlackTree<pair ,std::less<pair::first_type>,  alloc >();
	std::vector<node<pair> *> nodes;
	srand(5);
	// insert and delete random nodes in the tree
	// std::vector<std::pair<int, int> >  random_instructions;
	// std::vector<int> tmp;
	// for (int i = 0; i < 10000; ++i) {
	// 	const int operation = rand() % 2;
	// 	if (operation == 0 || tmp.empty()) {
	// 		const int key = rand() % 10000;
	// 		random_instructions.push_back(std::make_pair(0, key));
	// 		tmp.push_back(key);
	// 	} else {
	// 		const int index = rand() % tmp.size();
	// 		tmp.erase(tmp.begin() + index);
	// 		random_instructions.push_back(std::make_pair(1, index));
	// 	}
	// }
	// for (int i = 0; i < 10; ++i) {
	// 	// const int operation = rand() % 2;
	// 	// if (operation == 0 || nodes.empty()) {
	// 		const int key = rand() % 10000;
	// 		node_pair *n = new node_pair(pair(key, 0));
	// 		nodes.push_back(n);
	// 		std::cout << "**************\n";
	// 		std::cout << "to insert " << key << std::endl;
	// 		std::cout << "**************\n";
	// 		tree->insertNode(n);
	// 		std::cout << "**************\n";
	// 		std::cout << "inserted " << key << std::endl;
	// 		std::cout << "**************\n";
	// 	// } else {
	// 	// 	const int key = rand() % nodes.size();
	// 	// 	node_pair *node = nodes[key];
	// 	// 	nodes.erase(nodes.begin() + key);
	// 	// 	std::cout << "**************\n";
	// 	// 	std::cout << "deleted " << node->key << std::endl;
	// 	// 	std::cout << "**************\n";
	// 	// 	tree->deleteNode(node);
	// 	// }
	// 	tree->draw();
	// 	std::cout << std::endl;
	// }
	node_pair *n1 = new node_pair(pair (1, 1));
	node_pair *n2 = new node_pair(pair(2, 1));
	node_pair *n3 = new node_pair(pair(0, 1));
	node_pair *n4 = new node_pair(pair(4, 1));
	node_pair *n5 = new node_pair(pair(3, 1));
	tree->insertNode(n1);
	tree->draw();
	std::cout << std::endl;
	tree->insertNode(n2);
	tree->draw();
	std::cout << std::endl;
	tree->insertNode(n3);
	tree->draw();
	std::cout << std::endl;
	tree->insertNode(n4);
	tree->draw();
	std::cout << std::endl;
	tree->insertNode(n5);
	tree->draw();
	std::cout << std::endl;
}