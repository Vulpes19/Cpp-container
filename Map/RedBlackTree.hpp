/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/16 14:09:10 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define RED 'r'
#define BLACK 'b'

template < typename Key, typename T >

struct node
{
	T		value;
	Key		key;
	char	color;
	node<Key, T> *parent;
	node<Key, T> *right;
	node<Key, T> *left;

	node( Key key, T value, char color = RED, node *left = makeNIL(), node *right = makeNIL(), node *parent = makeNIL() ) : value(value), key(key), color(color), parent(parent), right(right), left(left) {};
	static node<Key, T>	*makeNIL( void )
	{
		return ( new node( Key(), T(), BLACK, NULL, NULL, NULL ) );
	}
	bool	operator==( const node<Key, T> *x )
	{
		return ( key == x->key );
	}
	bool	operator!=( const node<Key, T> *x )
	{
		return ( key != x->key );
	}
	bool	operator>( const node<Key, T> *x )
	{
		return ( key > x->key );
	}
	bool	operator<( const node<Key, T> *x )
	{
		return ( key < x->key );
	}
};

template < typename Key, typename T >

class RedBlackTree
{
	public:
		RedBlackTree( void )
		{
			nil = new node<Key, T>( Key(), T(), BLACK, NULL, NULL, NULL );
			root = nil;
		}
		//insertion
		void	insertNode( node<Key, T> *newNode )
		{
			node<Key, T> *tmpParent = nil;
			node<Key, T> *tmpRoot = root;
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
			if ( newNode->parent->parent == NULL || newNode->parent->parent == nil )
				return ;
			fixInsert( newNode );
		};
		//LEFT ROTATE
		void leftRotate( node<Key, T> *toRotate )
		{
			node<Key, T> *tmp = toRotate->right;
			toRotate->right = tmp->left;
			if ( toRotate && tmp->left != NULL && tmp->left != nil )
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
		void rightRotate( node<Key, T> *toRotate )
		{
			node<Key, T> *tmp = toRotate->left;
			toRotate->left = tmp->right;
			if ( toRotate && toRotate->left != NULL && toRotate->left != nil )
			{
				// std::cout << "right key: " << tmp->right->color << std::endl;
				// std::cout << "hello: " << toRotate->key << std::endl;
				toRotate->left->parent = toRotate;
			}
			tmp->parent = toRotate->parent;
			if ( toRotate->parent == nil )
				root = tmp;
			else if ( toRotate == toRotate->parent->left )
				toRotate->parent->left = tmp;
			else
				toRotate->parent->right = tmp;
			tmp->right = toRotate;
			toRotate->parent = tmp;
		}

		//fix_insertion
		void	fixInsert( node<Key, T> *insertedNode )
		{
			while ( insertedNode->parent->color == RED )
			{
				if ( insertedNode->parent == insertedNode->parent->parent->left )
				{
					node<Key, T> *tmp = insertedNode->parent->parent->right;
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
					if ( insertedNode->parent->parent )
					{	
						insertedNode->parent->parent->color = RED;
						rightRotate( insertedNode->parent->parent );
					}
				}
				else
				{
					node<Key, T> *tmp = insertedNode->parent->parent->left;
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
						rightRotate( insertedNode );
					}
					insertedNode->parent->color = BLACK;
					if ( insertedNode->parent->parent )
					{
						insertedNode->parent->parent->color = RED;
						leftRotate( insertedNode->parent->parent );
					}
				}
				if ( insertedNode == root )
					break ;
			}
			root->color = BLACK;
		}
		node<Key, T> *getRoot( void ) const { return ( root ); };
		void print( node<Key, T> *root )
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
		node<Key, T>	*root;
		node<Key, T>	*nil;
};