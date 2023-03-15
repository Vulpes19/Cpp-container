/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/15 12:16:21 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define RED 'r'
#define BLACK 'b'

template < typename T, typename Key >

struct node
{
	T		value;
	Key		key;
	char	color;
	node<T, Key> *parent;
	node<T, Key> *right;
	node<T, Key> *left;

	node( T value, Key key, char color = RED, node *left = NULL, node *right = NULL, node *parent = NULL) : value(value), key(key), color(color), parent(parent), right(right), left(left) {}
};

template < typename T, typename Key >

class RedBlackTree
{
	public:
		RedBlackTree( void )
		{
			nil = new node<T, Key>( T(), Key(), BLACK );
			root = nil;
		}
		//insertion
		void	insertNode( node<T, Key> *newNode )
		{
			node<T, Key> *tmpParent = nil;
			node<T, Key> *tmpRoot = root;
			while ( tmpRoot != nil )
			{
				tmpParent = tmpRoot;
				if ( newNode->key < tmpRoot->key )
					tmpRoot = tmpRoot->left;
				else
					tmpRoot = tmpRoot->right;
			}
			newNode->parent = tmpParent;
			if ( tmpParent == nil )
				root = newNode;
			else if ( newNode->key < tmpParent->key )
				tmpParent->left = newNode;
			else
				tmpParent->right = newNode;
			newNode->left = nil;
			newNode->right = nil;
			newNode->color = RED;
			fixInsert( newNode );
		};
		//LEFT ROTATE
		void leftRotate( node<T, Key> *toRotate )
		{
			node<T, Key> *tmp = toRotate->right;
			toRotate->right = tmp->left;
			if ( tmp->left != nil )
				tmp->left->parent = toRotate;
			tmp->parent = toRotate->parent;
			if ( toRotate->parent == nil )
				root = tmp;
			else if ( toRotate == toRotate->parent->left )
				toRotate->parent->left = tmp;
			else
				toRotate->parent->right = tmp;
			tmp->left = toRotate;
			toRotate->parent = tmp;
		}
		//RIGHT ROTATE
		void rightRotate( node<T, Key> *toRotate )
		{
			node<T, Key> *tmp = toRotate->left;
			toRotate->left = tmp->right;
			if ( tmp->right != nil )
				tmp->right->parent = toRotate;
			tmp->parent = toRotate->parent;
			if ( toRotate->parent == nil )
				root = tmp;
			else if ( toRotate == toRotate->parent->right )
				toRotate->parent->right = tmp;
			else
				toRotate->parent->left = tmp;
			tmp->right = toRotate;
			toRotate->parent = tmp;
		}

		//fix_insertion
		void	fixInsert( node<T, Key> *insertedNode )
		{
			while ( insertedNode->parent->color == RED )
			{
				if ( insertedNode->parent == insertedNode->parent->parent->left )
				{
					node<T, Key> *tmp = insertedNode->parent->parent->right;
					if ( tmp->color == RED )
					{
						insertedNode->parent->color = BLACK;
						tmp->color = BLACK;
						insertedNode->parent->parent->color = RED;
						insertedNode = insertedNode->parent->parent;
					}
					else if ( insertedNode == insertedNode->parent->right )
					{
						insertedNode = insertedNode->parent;
						leftRotate( insertedNode );
					}
					insertedNode->parent->color = BLACK;
					insertedNode->parent->parent->color = RED;
					rightRotate( insertedNode );
				}
				else
				{
					node<T, Key> *tmp = insertedNode->parent->parent->left;
					if ( tmp->color == RED )
					{
						insertedNode->parent->color = BLACK;
						tmp->color = BLACK;
						insertedNode->parent->parent->color = RED;
						insertedNode = insertedNode->parent->parent;
					}
					else if ( insertedNode == insertedNode->parent->left )
					{
						insertedNode = insertedNode->parent;
						leftRotate( insertedNode );
					}
					insertedNode->parent->color = BLACK;
					insertedNode->parent->parent->color = RED;
					rightRotate( insertedNode );
				}
			}
			root->color = BLACK;
		}
		node<T, Key> *getRoot( void ) const { return ( root ); };
		void print( node<T, Key> *root )
		{
			if ( root == nil )
				return ;
			std::cout << "value: " << root->value << " key: " << root->key << std::endl;
			print(root->left);
			print(root->right);
		}
		//deletion
		//Search
		//Minimum
		//Maximum
		//Successor
		//Predecessor
		//Traversal
	private:
		node<T, Key>	*root;
		node<T, Key>	*nil;
};