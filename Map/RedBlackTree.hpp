/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:02:37 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/18 19:41:26 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define RED 'r'
#define BLACK 'b'
#define LEFT_DIR 'L'
#define RIGHT_DIR 'R'


template < typename pair, typename Allocator = std::allocator< pair > >

struct node
{
	typedef typename pair::first_type	key_type;
	typedef typename pair::second_type 	value_type; 
	value_type	value;
	key_type	key;
	char	color;
	node<pair, Allocator> *parent;
	node<pair, Allocator> *right;
	node<pair, Allocator> *left;

	node( void ) : key(key_type()), value(value_type()), color('b'), left(NULL), right(NULL), parent(NULL) {};
	node( key_type key, value_type value, char color = RED, node *left = makeNIL(Allocator()), node *right = makeNIL(Allocator()), node *parent = makeNIL(Allocator()) ) : value(value), key(key), color(color), parent(parent), right(right), left(left) {};
	static node<pair, Allocator>	*makeNIL( const Allocator &a )
	{
		node<pair, Allocator> *ret = a.allocate(1);
		return ( a.construct( ret, node<pair, Allocator>(key_type(), value_type(), BLACK, NULL, NULL, NULL ) ));
	}
	bool	operator==( const node<pair, Allocator> *x )
	{
		return ( key == x->key );
	}
	bool	operator!=( const node<pair, Allocator> *x )
	{
		return ( key != x->key );
	}
	bool	operator>( const node<pair, Allocator> *x )
	{
		return ( key > x->key );
	}
	bool	operator<( const node<pair, Allocator> *x )
	{
		return ( key < x->key );
	}

	private:
		Allocator _alloc;
};

template < typename pair, typename Comp = std::less< typename pair::first_type > , typename Allocator = std::allocator< pair > >

class RedBlackTree
{
	public:
		typedef typename pair::first_type key_type;
		typedef typename pair::second_type value_type;
		RedBlackTree( void )
		{
			std::allocator_traits<Allocator>::construct( _alloc, nil, key_type(), value_type(), BLACK, NULL, NULL, NULL );
			// nil = _alloc.allocate(node<pair, Allocator>( key_type(), value_type(), BLACK, NULL, NULL, NULL ));
			root = nil;
		}
		//insertion
		void	insertNode( node<pair, Allocator> *newNode )
		{
			node<pair, Allocator> *tmpParent = nil;
			node<pair, Allocator> *tmpRoot = root;
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
			else if ( compare(newNode->key, tmpParent->Key) )
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
		void leftRotate( node<pair, Allocator> *toRotate )
		{
			node<pair, Allocator> *tmp = toRotate->right;
			toRotate->right = tmp->left;
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
		void rightRotate( node<pair, Allocator> *toRotate )
		{
			node<pair, Allocator> *tmp = toRotate->left;
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
		void	fixInsert( node<pair, Allocator> *insertedNode )
		{
			while ( insertedNode->parent->color == RED )
			{
				if ( insertedNode->parent == insertedNode->parent->parent->left )
				{
					node<pair, Allocator> *tmp = getUncle( insertedNode, RIGHT_DIR );
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
					node<pair, Allocator> *tmp = getUncle( insertedNode, LEFT_DIR );
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
		node<pair, Allocator> *getRoot( void ) const { return ( root ); };
		
		void print( node<pair, Allocator> *root )
		{
			if ( root == nil )
				return ;
			std::cout << "value: " << root->value << " key: " << root->key << std::endl;
			print(root->left);
			print(root->right);
		};

		node<pair, Allocator> *getUncle( node<pair, Allocator> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->parent->right );
			return (NULL);
		};

		node<pair, Allocator> *getSibling( node<pair, Allocator> *n, char dir )
		{ 
			if ( dir == LEFT_DIR )
				return ( n->parent->left );
			else if ( dir == RIGHT_DIR )
				return ( n->parent->right );
			return (NULL);
		};
		//deletion
		void	transplant( node<pair, Allocator> *x, node<pair, Allocator> *y )
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

		void    _draw(node<pair, Allocator> *node)
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
		void	fixDelete( node<pair, Allocator> *n )
		{
			while ( n != root && n->color == BLACK )
			{
				if ( n == n->parent->left )
				{
					node<pair, Allocator> *sibling = n->parent->right;
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
					node<pair, Allocator> *sibling = n->parent->left;
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

		void	deleteNode( node<pair, Allocator> *n )
		{
			node<pair, Allocator> *savedNode = n;
			node<pair, Allocator> *x = nil;
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
		node<pair, Allocator>	*minimum( node<pair, Allocator> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->left && n->left != nil )
				n = n->left;
			return (n);
		}
		//Maximum
		node<pair, Allocator>	*maximum( node<pair, Allocator> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			while ( n->right && n->right != nil )
				n = n->right;
			return (n);
		}
		//Successor
		node<pair, Allocator>	*successor( node<pair, Allocator> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			if ( n->right && n->right != nil )
				return ( minimum(n->right) );	
		}
		//Predecessor
		node<pair, Allocator>	*predecessor( node<pair, Allocator> *n ) const
		{
			if ( n == NULL || n == nil )
				return (n);
			if ( n->left && n->left != nil )
				return ( maximum(n->left) );	
		}
		//Traversal
	private:
		node<pair, Allocator>	*root;
		node<pair, Allocator>	*nil;
		Allocator				_alloc;
		Comp					compare;
};