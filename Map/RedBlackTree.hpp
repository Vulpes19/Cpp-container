/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/18 14:03:33 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define RED 'r'
#define BLACK 'b'
#define LEFT_DIR 'L'
#define RIGHT_DIR 'R'


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
			std::cout << toRotate->key << std::endl;
			if ( toRotate != nil && tmp->left != NULL && tmp->left != nil )
				tmp->left->parent = toRotate;
			tmp->parent = toRotate->parent;
			if ( toRotate->parent && toRotate->parent == nil )
				root = tmp;
			else if ( toRotate && toRotate == toRotate->parent->left )
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
			if ( toRotate != nil && toRotate->left != NULL && toRotate->left != nil )
				toRotate->left->parent = toRotate;
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
					std::cout << "hello1\n";
					node<Key, T> *tmp = getUncle( insertedNode, RIGHT_DIR );
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
					if ( insertedNode->parent->parent && insertedNode->parent->parent != nil )
					{	
						insertedNode->parent->parent->color = RED;
						rightRotate( insertedNode->parent->parent );
					}
				}
				else
				{
					std::cout << "hello2\n";
					node<Key, T> *tmp = getUncle( insertedNode, LEFT_DIR );
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
					if ( insertedNode->parent->parent && insertedNode->parent->parent != nil )
					{
						std::cout << insertedNode->parent->parent->key << std::endl;
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
		};

		node<Key, T> *getUncle( node<Key, T> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->parent->right );
			return (NULL);
		};

		node<Key, T> *getSibling( node<Key, T> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->right );
			return (NULL);
		};
		//deletion
		void	transplant( node<Key, T> *x, node<Key, T> *y )
		{
			if ( x->parent == nil )
				root = y;
			else if ( x == x->parent->left )
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
		};
		void    draw()
		{
			_draw(root);
		}

		void    _draw(node<Key, T> *node)
		{
			if (!node) // if you have nil node ==> this should be if (node == nil_node)
			{
				std::cerr << "null";
				return;
			} 

			std::cerr << "{" << "data:" << node->key  // i don't think you need static cast in your case
							<< ", isblack:" << (node->color == BLACK ? "true" : "false") // check if color is black and print true if yes
							<< ",left :";
			_draw(node->left);
			std::cerr << ", right : ";
			_draw(node->right);
			std::cerr << "}";
		}
		void	fixDelete( node<Key, T> *n )
		{
			while ( n != root && n->color == BLACK )
			{
				if ( n == n->parent->left )
				{
					node<Key, T> *sibling = n->parent->right;
					//case 1
					if ( sibling->color == RED )
					{
						sibling->color = BLACK;
						n->parent->color = RED;
						leftRotate(n->parent);
						sibling = n->parent->right;
					}
					//case 2
					if ( sibling->left->color == BLACK && sibling->right->color == BLACK )
					{
						sibling->color = RED;
						n = n->parent;
					}
					//case 3
					else if ( sibling->right->color == BLACK )
					{
						sibling->right->color = BLACK;
						sibling->left->color = BLACK;
						sibling->color = BLACK;
						rightRotate(sibling);
						sibling = n->parent->right;
					}
					//case 4
					sibling->color = n->parent->color;
					n->parent->color = BLACK;
					sibling->right->color = BLACK;
					leftRotate(n->parent);
					n = root;
				}
				else
				{
					node<Key, T> *sibling = n->parent->left;
					//case 1
					if ( sibling->color == RED )
					{
						sibling->color = BLACK;
						n->parent->color = RED;
						leftRotate(n->parent);
						sibling = n->parent->left;
					}
					//case 2
					if ( sibling->left->color == BLACK && sibling->right->color == BLACK )
					{
						sibling->color = RED;
						n = n->parent;
					}
					//case 3
					else if ( sibling->left->color == BLACK )
					{
						sibling->right->color = BLACK;
						sibling->left->color = BLACK;
						sibling->color = BLACK;
						rightRotate(sibling);
						sibling = n->parent->right;
					}
					//case 4
					sibling->color = n->parent->color;
					n->parent->color = BLACK;
					sibling->right->color = BLACK;
					leftRotate(n->parent);
					n = root;
				}
			}
			n->color = BLACK;
		}

		void	deleteNode( node<Key, T> *n )
		{
			node<Key, T> *savedNode = n;
			node<Key, T> *x = nil;
			char savedColor = savedNode->color;
			if ( n->left == nil )
			{
				x = n->right;
				transplant( n, n->right );
			}
			else if ( n->right == nil )
			{
				x = n->left;
				transplant( n, n->left );
			}
			else
			{
				savedNode = minimum( n->right );
				savedColor = savedNode->color;
				x = savedNode->right;
				if ( savedNode->parent == n )
					x->parent = savedNode;
				else
				{
					transplant( savedNode, savedNode->right );
					savedNode->right = n->right;
					savedNode->right->parent = savedNode;
				}
				transplant( n, savedNode );
				savedNode->left = n->left;
				savedNode->left->parent = savedNode;
				savedNode->color = n->color;
			}
			if ( savedColor == BLACK )
				fixDelete( x );
		};
		//Search
		//Minimum
		node<Key, T>	*minimum( node<Key, T> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->left != nil )
				n = n->left;
			return (n);
		}
		//Maximum
		node<Key, T>	*maximum( node<Key, T> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->right != nil )
				n = n->right;
			return (n);
		}
		//Successor
		// node<Key, T>	*successor( node<Key, T> *n ) const
		// {
		// 	if ( n->right != nil )
		// 		return ( minimum(n->right) );
		// 	else
		// 		return 
		// }
		//Predecessor
		//Traversal
	private:
		node<Key, T>	*root;
		node<Key, T>	*nil;
};