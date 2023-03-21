/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/21 16:30:44 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "../Utility/Utility.hpp"
#include <cstdlib>
#define RED 'r'
#define BLACK 'b'
#define LEFT_DIR 'L'
#define RIGHT_DIR 'R'

template < typename node >

struct node_base {
	node *parent;
	node *left;
	node *right;
	char	color;

	node_base( void ) : parent(NULL), left(NULL), right(NULL), color(BLACK) {};
	node_base( node *parent, node *left, node *right, char color ) : parent(parent), left(left), right(right), color(color) {};
};
template < typename pair >

struct node: node_base< node<pair> >
{
	typedef typename pair::first_type	key_type;
	typedef typename pair::second_type 	value_type; 
	value_type	value;
	key_type	key;
	

	node( void ) : node_base< node<pair> >(NULL, NULL, NULL, BLACK), key(key_type()), value(value_type()) {};
	node( pair p, char color = RED, node *left= NULL , node *right = NULL, node *parent = NULL ) : node_base< node<pair> >(parent, left, right, color)
	{
		value = p.second;
		key = p.first;
	};
};

template < typename pair, typename Comp = std::less< typename pair::first_type > , typename Allocator = std::allocator< pair > >

class RedBlackTree
{
	public:
		typedef typename pair::first_type key_type;
		typedef typename pair::second_type value_type;
		typedef typename Allocator::template rebind< node<pair> >::other node_allocator;
		typedef typename Allocator::template rebind<  node_base<  node<pair> > >::other node_base_allocator;
		RedBlackTree( void )
		{
			nil = static_cast<node<pair> *> (node_base_allocator().allocate(1));
			node_base_allocator().construct( nil, node_base<node<pair> >(NULL, NULL, NULL, BLACK) );
			root = nil;
		}

		//insertion
		void	insertNode( node<pair> *newNode )
		{
			node<pair> *tmpParent = nil;
			node<pair> *tmpRoot = root;
			while ( tmpRoot != nil )
			{
				tmpParent = tmpRoot;
				if ( compare(newNode->key, tmpRoot->key) )
					tmpRoot = tmpRoot->left;
				else
					tmpRoot = tmpRoot->right;
			}
			newNode->parent = tmpParent;
			if ( tmpParent == nil )
				root = newNode;
			else if ( compare(newNode->key, tmpParent->key) )
				tmpParent->left = newNode;
			else
				tmpParent->right = newNode;
			newNode->left = nil;
			newNode->right = nil;
			newNode->color = RED;
			if ( newNode->parent == NULL || newNode->parent == nil )
			{	
				newNode->color = BLACK;
				return ;
			}
			fixInsert( newNode );
		};
		//LEFT ROTATE
		void leftRotate( node<pair> *toRotate )
		{
			if ( toRotate == NULL || toRotate == nil )
				return ;
			node<pair> *tmp = toRotate->right;
			if ( tmp->left == NULL )
				tmp->left = nil;
			if ( tmp->right == NULL )
				tmp->right = nil;
			toRotate->right = tmp->left;
			tmp->left->parent = toRotate;
			tmp->parent = toRotate->parent;
			if ( toRotate->parent == NULL || toRotate->parent == nil )
				root = tmp;
			else if ( toRotate && toRotate == toRotate->parent->left )
				toRotate->parent->left = tmp;
			else
				toRotate->parent->right = tmp;
			tmp->left = toRotate;
			toRotate->parent = tmp;
		}
		//RIGHT ROTATE
		void rightRotate( node<pair> *toRotate )
		{
			if ( toRotate == NULL || toRotate == nil )
				return ;
			node<pair> *tmp = toRotate->left;
			if ( tmp->left == NULL )
				tmp->left = nil;
			if ( tmp->right == NULL )
				tmp->right = nil;
			toRotate->left = tmp->right;
			tmp->right->parent = toRotate;
			tmp->parent = toRotate->parent;
			if ( toRotate->parent == NULL || toRotate->parent == nil )
				root = tmp;
			else if ( toRotate == toRotate->parent->right )
				toRotate->parent->right = tmp;
			else
				toRotate->parent->left = tmp;
			tmp->right = toRotate;
			toRotate->parent = tmp;
		}

		//fix_insertion
		void	fixInsert( node<pair> *insertedNode )
		{
			if ( insertedNode->parent->color == RED )
			{
				if ( insertedNode->parent == insertedNode->parent->parent->right )
				{
					node<pair> *uncle = getUncle( insertedNode, LEFT_DIR );
					if ( uncle->color == RED )
					{
						uncle->color = BLACK;
						insertedNode->parent->color = BLACK;
						insertedNode->parent->parent->color = RED;
						fixInsert(insertedNode->parent->parent);
						return ;
					}
					else if ( insertedNode == insertedNode->parent->left )
					{
						rightRotate(insertedNode);
					}
					leftRotate(insertedNode);
					insertedNode->color = BLACK;
					insertedNode->right->color = RED;
					insertedNode->left->color = RED;
				}
				else
				{
					node<pair> *uncle = getUncle( insertedNode, RIGHT_DIR );
					if ( uncle->color == RED )
					{
						uncle->color = BLACK;
						insertedNode->parent->color = BLACK;
						insertedNode->parent->parent->color = RED;
						fixInsert(insertedNode->parent->parent);
						return ;
					}
					else if ( insertedNode == insertedNode->parent->right )
					{
						leftRotate(insertedNode);
					}
					rightRotate(insertedNode);
					insertedNode->color = BLACK;
					insertedNode->right->color = RED;
					insertedNode->left->color = RED;
					// fixInsert(insertedNode->parent);
				}
			}
			root->color = BLACK;
			// while ( insertedNode->parent->color == RED )
			// {
			// 	if ( insertedNode->parent == insertedNode->parent->parent->left )
			// 	{
			// 		node<pair> *uncle = getUncle( insertedNode, RIGHT_DIR );
			// 		if ( uncle->color == RED )
			// 		{
			// 			insertedNode->parent->color = BLACK;
			// 			uncle->color = BLACK;
			// 			insertedNode->parent->parent->color = RED;
			// 			insertedNode = insertedNode->parent->parent;
			// 		}
			// 		else if ( insertedNode == insertedNode->parent->right )
			// 		{
			// 			insertedNode = insertedNode->parent;
			// 			leftRotate( insertedNode );
			// 		}
			// 		insertedNode->parent->color = BLACK;
			// 		if ( insertedNode->parent->parent )
			// 		{	
			// 			insertedNode->parent->parent->color = RED;
			// 			rightRotate( insertedNode->parent->parent );
			// 		}
			// 	}
			// 	else
			// 	{
			// 		node<pair> *uncle = getUncle( insertedNode, LEFT_DIR );
			// 		if ( uncle->color == RED )
			// 		{
			// 			insertedNode->parent->color = BLACK;
			// 			uncle->color = BLACK;
			// 			insertedNode->parent->parent->color = RED;
			// 			insertedNode = insertedNode->parent->parent;
			// 		}
			// 		else if ( insertedNode == insertedNode->parent->left )
			// 		{
			// 			std::cout << "I'm here " << insertedNode->key << std::endl;
			// 			insertedNode = insertedNode->parent;
			// 			rightRotate( insertedNode );
			// 		}
			// 		insertedNode->parent->color = BLACK;
			// 		if ( insertedNode->parent->parent )
			// 		{
			// 			insertedNode->parent->parent->color = RED;
			// 			leftRotate( insertedNode->parent->parent );
			// 		}
			// 	}
			// 	if ( insertedNode == root )
			// 		break ;
			// }
			// root->color = BLACK;
		}

		node<pair> *getRoot( void ) const { return ( root ); };
		
		void print( node<pair> *root )
		{
			if ( root == nil )
				return ;
			std::cout << "value: " << root->value << " key: " << root->key << std::endl;
			print(root->left);
			print(root->right);
		};

		node<pair> *getUncle( node<pair> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->parent->right );
			return (NULL);
		};

		node<pair> *getSibling( node<pair> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->right );
			return (NULL);
		};
		//deletion
		void	transplant( node<pair> *x, node<pair> *y )
		{
			if ( x->parent == nil )
				root = y;
			else if ( x == x->parent->left )
				x->parent->left = y;
			else if ( x == x->parent->right )
				x->parent->right = y;
			y->parent = x->parent;
		};
		void    draw()
		{
			_draw(root);
		}

		void    _draw(node<pair> *node)
		{
			if (node == nil) // if you have nil node ==> this should be if (node == nil_node)
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
		void	fixDelete( node<pair> *n )
		{
			node<pair> *sibling = NULL;

			while ( n != root && n->color == BLACK )
			{
				if ( n == n->parent->left )
				{
					sibling = n->parent->right;
					if ( sibling->color == RED )
					{
						sibling->color = BLACK;
						n->parent->color = RED;
						leftRotate(n->parent);
						sibling = n->parent->right;
					}
					if ( sibling->right && sibling->left && sibling->left->color == BLACK && sibling->right->color == BLACK )
					{
						sibling->color = RED;
						n = n->parent;
					}
					else if ( sibling->right && sibling->right->color == BLACK )
					{
						sibling->left->color = BLACK;
						sibling->color = RED;
						rightRotate(sibling);
						sibling = n->parent->right;
					}
					sibling->color = n->parent->color;
					n->parent->color = BLACK;
					if ( sibling->right )
						sibling->right->color = BLACK;
					// sibling->right->color = BLACK;
					leftRotate(n->parent);
					n = root;
				}
				else
				{
					sibling = n->parent->left;
					if ( sibling->color == RED )
					{
						sibling->color = BLACK;
						n->parent->color = RED;
						rightRotate(n->parent);
						sibling = n->parent->left;
					}
					if ( sibling->left && sibling->right && sibling->left->color == BLACK && sibling->right->color == BLACK )
					{
						sibling->color = RED;
						n = n->parent;
					}
					else if ( sibling->left && sibling->left->color == BLACK )
					{
						sibling->right->color = BLACK;
						sibling->color = RED;
						leftRotate(sibling);
						sibling = n->parent->left;
					}
					sibling->color = n->parent->color;
					n->parent->color = BLACK;
					if ( sibling->left )
						sibling->left->color = BLACK;
					// sibling->left->color = BLACK;
					rightRotate(n->parent);
					n = root;
				}
			}
			n->color = BLACK;
		}

		void	deleteNode( node<pair> *n )
		{
			node<pair> *savedNode = n;
			node<pair> *x = nil;
			char savedColor = savedNode->color;
			if ( n == root && n->left == nil && n->right == nil )
			{
				root = nil;
				return ;
			}
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
		node<pair>	*minimum( node<pair> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->left && n->left != nil )
				n = n->left;
			return (n);
		}
		//Maximum
		node<pair>	*maximum( node<pair> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->right && n->right != nil )
				n = n->right;
			return (n);
		}
		//Successor
		node<pair>	*successor( node<pair> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			if ( n->right && n->right != nil )
				return ( minimum(n->right) );	
		}
		//Predecessor
		node<pair>	*predecessor( node<pair> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			if ( n->left && n->left != nil )
				return ( maximum(n->left) );	
		}
		//Traversal
	private:
		node<pair>				*root;
		node<pair>				*nil;
		node_allocator		    _alloc;
		Comp					compare;
};