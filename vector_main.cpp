/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/03/10 11:12:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "TypeTraits.hpp"
#include "Utility.hpp"
#include <vector>
#include <typeinfo>
#include <time.h>
#include <iostream>
#include <cassert>
#include <sstream>

typedef ft::vector<int>::iterator myIterator;
typedef std::vector<int>::iterator stdIterator;

template<typename T>
void	printVecElements( ft::vector<T> &vec )
{
	std::cout << "****my vector****" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

template<typename T>
void	printVecElements( std::vector<T> &vec )
{
	std::cout << "****std vector****" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

template<typename T>
void	printSizeAndCapacity( ft::vector<T> &vec )
{
	std::cout << "****my vector****" << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

template<typename T>
void	printSizeAndCapacity( std::vector<T> &vec )
{
	std::cout << "****std vector****" << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;
}

void	printTime( clock_t start, clock_t end, std::string str )
{
	std::cout << "****TIME****" << std::endl;
	std::cout << str << ": " << ((double)(end - start)) / CLOCKS_PER_SEC << std::endl;
}

void	testing_vec_constructors( void )
{
	ft::vector<int> ftvec;
	std::vector<int> stdvec;
	if ( ftvec.empty() ) std::cout << "my vec is empty\n";
	if ( stdvec.empty() ) std::cout << "std vec is empty\n";
	if ( typeid(ftvec.get_allocator()) == typeid(stdvec.get_allocator()) ) std::cout << "vectors have the same allocator type\n";
	else	std::cout << "vectors don't have the same allocator type\n";
	ft::vector<int> ftvec2(5, 10);
	std::vector<int> stdvec2(5, 10);

	printSizeAndCapacity(ftvec2);
	printSizeAndCapacity(stdvec2);
	printVecElements(ftvec2);
	printVecElements(stdvec2);

	stdIterator std_begin = stdvec2.begin();
	stdIterator std_end = stdvec2.end();

	ft::vector<int> ftvec3( std_begin, std_end );
	std::vector<int> stdvec3( std_begin, std_end );

	printVecElements(ftvec3);
	printVecElements(stdvec3);

	ftvec = ftvec3;
	printVecElements(ftvec);
}

void	testing_push_back( void )
{
	clock_t start, end;
	/* testing push_back*/
	ft::vector<char> vec(3, 'a');
	std::vector<char> og_vec(3, 'a');
	ft::vector<int> empty;
	std::vector<int> og_empty;

	printSizeAndCapacity(empty);
	printSizeAndCapacity(og_empty);
	start = clock();
	empty.push_back(1);
	end = clock();
	printTime(start, end, "std");
	start = clock();
	og_empty.push_back(1);
	end = clock();
	printTime(start, end, "ft");
	printVecElements(empty);
	printVecElements(og_empty);
	printSizeAndCapacity(empty);
	printSizeAndCapacity(og_empty);
}

void	testing_assign( void )
{
	clock_t start, stop;
	std::vector<int> vec(4, 1);
	std::vector<int> vec3(3, 9);
	std::vector<std::string> std_vec_char(4, "Ayman");
	ft::vector<std::string> ft_vec_char(4, "Ayman");
	printVecElements(std_vec_char);
	printVecElements(ft_vec_char);
	std_vec_char.assign(0, "");
	ft_vec_char.assign(0, "");
	printVecElements(std_vec_char);
	printVecElements(ft_vec_char);
	ft::vector<int> vec2(3, 9);
	stdIterator begin = vec.begin();
	myIterator begin2 = vec2.begin();
	stdIterator end = vec.end();
	myIterator end2 = vec2.end();
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec2);
	printVecElements(vec3);
	printVecElements(vec2);
	start = clock();
	vec3.assign( begin, end );
	stop = clock();
	printTime(start, stop, "std");
	start = clock();
	vec2.assign( begin, end );
	stop = clock();
	printTime(start, stop, "ft");
	printVecElements(vec3);
	printVecElements(vec2);
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec2);
	std::cout << "**************\n";
	std::cout << "**************\n";
	std::cout << "**************\n";
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec2);
	printVecElements(vec3);
	printVecElements(vec2);
	start = clock();
	vec3.assign( 10, -1 );
	stop = clock();
	printTime(start, stop, "std");
	start = clock();
	vec2.assign( 10, -1 );
	stop = clock();
	printTime(start, stop, "ft");
	printVecElements(vec3);
	printVecElements(vec2);
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec2);
	std::cout << "**************\n";
	std::cout << "**************\n";
	std::cout << "**************\n";
	start = clock();
	vec3.assign(0, 4);
	stop = clock();
	printTime(start, stop, "std");
	start = clock();
	vec2.assign(0, 4);
	stop = clock();
	printTime(start, stop, "ft");
	printVecElements(vec3);
	printVecElements(vec2);
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec2);
}

void	testing_reverse_iterator( void )
{
	std::vector<int> vec(5, 9);
	stdIterator iter_end;
	stdIterator iter_begin;
	vec.push_back(10);
	iter_end = vec.begin();
	iter_begin = vec.end();

	std::reverse_iterator<stdIterator> stdrev1(iter_end);
	std::reverse_iterator<stdIterator> stdrev2(iter_begin);
	ft::reverse_iterator<stdIterator> rev_until(iter_end);
	ft::reverse_iterator<stdIterator> rev_from(iter_begin);
	// 	std::cout << *rev_until << std::endl;
	// exit(1);
	while ( rev_from != rev_until )
	{
		std::cout << *rev_from++ << std::endl;
	}
	std::cout << std::endl;
	while ( stdrev2 != stdrev1 )
	{
		std::cout << *stdrev2++ << std::endl;
	}

	ft::reverse_iterator<stdIterator> my_rev_op(iter_begin);
	std::reverse_iterator<stdIterator> std_rev_op(iter_begin);

	my_rev_op++;
	std_rev_op++;
	std::cout << *my_rev_op << " " << *std_rev_op << std::endl;
	my_rev_op += 3;
	std_rev_op += 3;
	std::cout << *my_rev_op << " " << *std_rev_op << std::endl;
	my_rev_op -= 2;
	std_rev_op -= 2;
	std::cout << *my_rev_op << " " << *std_rev_op << std::endl;
	
	my_rev_op--;
	std_rev_op--;
	std::cout << *my_rev_op << " > " << *rev_until << std::endl;
	if (my_rev_op > rev_until)
		std::cout << "1\n";
	else
		std::cout << "0\n";
	std::cout << *my_rev_op << " < " << *rev_until << std::endl;
	if (my_rev_op < rev_until)
		std::cout << "1\n";
	else
		std::cout << "0\n";
	std::cout << *std_rev_op << " > " << *stdrev1 << std::endl;
	if (std_rev_op > stdrev1)
		std::cout << "1\n";
	else
		std::cout << "0\n";
	std::cout << *std_rev_op << " < " << *stdrev1 << std::endl;
	if (std_rev_op < stdrev1)
		std::cout << "1\n";
	else
		std::cout << "0\n";
}

void	testing_insert( void )
{
	// std::vector<int> vec(5, 1);
	// ft::vector<int> ftvec(5, 1);
	// std::vector<int> c(4, 9);

	// stdIterator it = vec.begin();
	// it++;
	// myIterator it2 = ftvec.begin();
	// it2++;
	// stdIterator begin = c.begin();
	// stdIterator end = c.end();
	// printSizeAndCapacity(vec);
	// printSizeAndCapacity(ftvec);
	// printVecElements(vec);
	// printVecElements(ftvec);
	// vec.insert( it, begin, end);
	// ftvec.insert( it2, begin, end);
	// printSizeAndCapacity(vec);
	// printSizeAndCapacity(ftvec);
	// printVecElements(vec);
	// printVecElements(ftvec);

	// it = vec.begin() + 2;
	// it2 = ftvec.begin() + 2;
	// vec.insert( it, 2, -9);
	// ftvec.insert( it2, 2, -9);
	// printSizeAndCapacity(vec);
	// printSizeAndCapacity(ftvec);
	// printVecElements(vec);
	// printVecElements(ftvec);

	// it = vec.begin() + 1;
	// it2 = ftvec.begin() + 1;
	// {
	// 	std::vector<int> vec2;
	// 	ft::vector<int> ftvec2;
	// 	vec2.insert(vec2.begin(), 0, 64 );
	// 	ftvec2.insert(ftvec2.begin(), 0, 64 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.end(), 0, 64 );
	// 	ftvec2.insert(ftvec2.end(), 0, 64 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.end(), 10, 64 );
	// 	ftvec2.insert(ftvec2.end(), 10, 64 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.begin(), 5, -1 );
	// 	ftvec2.insert(ftvec2.begin(), 5, -1 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.begin() + 1, 1, -9 );
	// 	ftvec2.insert(ftvec2.begin() + 1, 1, -9 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.begin() + 7, 21, 88 );
	// 	ftvec2.insert(ftvec2.begin() + 7, 21, 88 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.begin(), 0, 2 );
	// 	ftvec2.insert(ftvec2.begin(), 0, 2 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.end(), 0, 4 );
	// 	ftvec2.insert(ftvec2.end(), 0, 4 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// 	vec2.insert(vec2.end(), 18, 420 );
	// 	ftvec2.insert(ftvec2.end(), 18, 420 );
	// 	printSizeAndCapacity(vec2);
	// 	printSizeAndCapacity(ftvec2);
	// 	printVecElements(vec2);
	// 	printVecElements(ftvec2);
	// }
	// {
	// 	ft::vector<std::string> ft_vec;
	// 	std::vector<std::string> std_vec;
	// 	std::string s1[5] = {
	// 		"ayman",
	// 		"AYMAN",
	// 		"AYYYMANNN",
	// 		"HELLO",
	// 		"HEY"
	// 	};

	// 	std::string s2[5] = {
	// 		"SAY MY NAME",
	// 		"YOU'RE GOD DAMN RIGHT",
	// 		"WE NEED TO COOK",
	// 		"HEISENBERG",
	// 		"AMOGUS"
	// 	};

	// 	ft_vec.insert(ft_vec.begin(), ft_vec.begin(), ft_vec.begin());
	// 	std_vec.insert(std_vec.begin(), std_vec.begin(), std_vec.begin());
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.begin(), ft_vec.begin(), ft_vec.end());
	// 	std_vec.insert(std_vec.begin(), std_vec.begin(), std_vec.end());
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.end(), ft_vec.begin(), ft_vec.end());
	// 	std_vec.insert(std_vec.end(), std_vec.begin(), std_vec.end());
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.begin(), s1, s1 + 5);
	// 	std_vec.insert(std_vec.begin(), s1, s1 + 5);
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.begin(), s2, s2 + 2);
	// 	std_vec.insert(std_vec.begin(), s2, s2 + 2);
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.begin() + 3, s2, s2 + 5);
	// 	std_vec.insert(std_vec.begin() + 3, s2, s2 + 5);
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	ft_vec.insert(ft_vec.end(), s1 + 2, s1 + 5);
	// 	std_vec.insert(std_vec.end(), s1 + 2, s1 + 5);
	// 	printVecElements(ft_vec);
	// 	printVecElements(std_vec);
	// 	printSizeAndCapacity(ft_vec);
	// 	printSizeAndCapacity(std_vec);
	// 	std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
	// 	std::istringstream str2("1 2 3 4 5 6 7 8 9 0 A B C D E F");
    //     std::istreambuf_iterator<char> it(str), end, it2(str2);
	// 	ft::vector<char> ftvec(2, 'U');
	// 	std::vector<char> stdvec(2, 'U');
	// 	printVecElements(ftvec);
	// 	printVecElements(stdvec);
	// 	printSizeAndCapacity(ftvec);
	// 	printSizeAndCapacity(stdvec);
	// 	ftvec.insert(ftvec.end(), it, end);
	// 	stdvec.insert(stdvec.end(), it2, end);
	// 	printVecElements(ftvec);
	// 	printVecElements(stdvec);
	// 	printSizeAndCapacity(ftvec);
	// 	printSizeAndCapacity(stdvec);
	// }
	{
		std::vector<int> vec(6, 1);
		ft::vector<int> ftvec(6, 1);

		printVecElements(vec);
		printVecElements(ftvec);
		vec.insert( vec.begin(), 3, 9);
		ftvec.insert( ftvec.begin(), 3, 9);

		printSizeAndCapacity(vec);
		printSizeAndCapacity(ftvec);
		printVecElements(vec);
		printVecElements(ftvec);
		// vec.insert(vec.begin(), 0, 64);
		// ftvec.insert(ftvec.begin(), 0, 64);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.end(), 0, 64);
		// ftvec.insert(ftvec.end(), 0, 64);

		// vec.insert(vec.end(), 10, 64);
		// ftvec.insert(ftvec.end(), 10, 64);
		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);

		// vec.insert(vec.begin() + 5, 3, 1);
		// ftvec.insert(ftvec.begin() + 5, 3, 1);
		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.begin() + 5, 5, 9);
		// ftvec.insert(ftvec.begin() + 5, 5, 9);
		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.begin(), 5, -1);
		// ftvec.insert(ftvec.begin(), 5, -1);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.begin() + 1, 1, -9);
		// ftvec.insert(ftvec.begin() + 1, 1, -9);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.begin() + 7, 21, 88);
		// ftvec.insert(ftvec.end() + 7, 21, 88);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.begin(), 0, 2);
		// ftvec.insert(ftvec.begin(), 0, 2);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.end(), 0, 4);
		// ftvec.insert(ftvec.end(), 0, 4);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
		// vec.insert(vec.end(), 18, 420);
		// ftvec.insert(ftvec.end(), 18, 420);

		// printSizeAndCapacity(vec);
		// printSizeAndCapacity(ftvec);
		// printVecElements(vec);
		// printVecElements(ftvec);
	}
}

void	testing_iterator_traits( void )
{
	int arr[] = {1, 2, 3};
	int *a = arr;
	int *b = arr + 3;
	std::cout << ft::distance(a, b) << std::endl;
	if ( typeid(ft::iterator_traits<stdIterator>::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "random access iterator\n";
	if ( typeid(ft::iterator_traits<myIterator>::iterator_category) == typeid(ft::random_access_iterator_tag))
		std::cout << "random access iterator\n";
	if ( typeid(ft::iterator_traits<int *>::iterator_category) == typeid(ft::random_access_iterator_tag))
		std::cout << "random access iterator\n";
}

bool mypredicate (int i, int j)
{
  return (i == j);
}

bool mycomp (char c1, char c2)
{ 
	return std::tolower(c1)<std::tolower(c2);
}

void	testing_algorithm( void )
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	std::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	std::vector<int> v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(4);
	std::vector<int> v4;
	v4.push_back(1);
	v4.push_back(2);
	std::vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(4);

	// Test equal
	std::cout << "Test std::equal" << std::endl;
	std::cout << "v1 == v2: " << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
	std::cout << "v1 == v3: " << std::equal(v1.begin(), v1.end(), v3.begin()) << std::endl;
	std::cout << "v1 == v4: " << std::equal(v1.begin(), v1.end(), v4.begin()) << std::endl;
	std::cout << "v1 == v5: " << std::equal(v1.begin(), v1.end(), v5.begin()) << std::endl;
	std::cout << std::endl;
	std::cout << "Test ft::equal" << std::endl;
	std::cout << "v1 == v2: " << ft::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
	std::cout << "v1 == v3: " << ft::equal(v1.begin(), v1.end(), v3.begin()) << std::endl;
	std::cout << "v1 == v4: " << ft::equal(v1.begin(), v1.end(), v4.begin()) << std::endl;
	std::cout << "v1 == v5: " << ft::equal(v1.begin(), v1.end(), v5.begin()) << std::endl;
	std::cout << std::endl;

	// Test lexicographical_compare
	std::cout << "Test std::lexicographical_compare" << std::endl;
	std::cout << "v1 < v2: " << std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	std::cout << "v1 < v3: " << std::lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()) << std::endl;
	std::cout << "v1 < v4: " << std::lexicographical_compare(v1.begin(), v1.end(), v4.begin(), v4.end()) << std::endl;
	std::cout << "v1 < v5: " << std::lexicographical_compare(v1.begin(), v1.end(), v5.begin(), v5.end()) << std::endl;
	std::cout << std::endl;
	std::cout << "Test ft::lexicographical_compare" << std::endl;
	std::cout << "v1 < v2: " << ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) << std::endl;
	std::cout << "v1 < v3: " << ft::lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()) << std::endl;
	std::cout << "v1 < v4: " << ft::lexicographical_compare(v1.begin(), v1.end(), v4.begin(), v4.end()) << std::endl;
	std::cout << "v1 < v5: " << ft::lexicographical_compare(v1.begin(), v1.end(), v5.begin(), v5.end()) << std::endl;
	std::cout << std::endl;
}

void	testing_utility( void )
{
	std::pair<int, int> p(4, 2);
	std::pair<int, int> pc(6, 9);
	std::cout << p.first << p.second << std::endl;
	ft::pair<int, int> p2(4, 2);
	ft::pair<int, int> pc2(6, 9);
	p2 = pc2;
	std::cout << p2.first << p2.second << std::endl;
	swap(pc, p);
	std::cout << p.first << p.second << std::endl;
	std::cout << pc.first << pc.second << std::endl;
	p2.swap(pc2);
	std::cout << p2.first << p2.second << std::endl;
	std::cout << pc2.first << pc2.second << std::endl;

	if (p2 == pc2) std::cout << "hello\n";
	if (p2 != pc2) std::cout << "bye bye\n";
}

void	testing_relational_op( void )
{
	ft::vector<char> foo (3,'b');   // three ints with a value of 100
	ft::vector<char> bar (2,'a');  // two ints with a value of 200

	swap( foo, bar);
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void	testing_erase( void )
{
	myIterator ft_ret;
	stdIterator std_ret;
	ft::vector<int> ftvec;
	ftvec.push_back(1);
	ftvec.push_back(2);
	ftvec.push_back(3);
	std::vector<int> stdvec;
	stdvec.push_back(1);
	stdvec.push_back(2);
	stdvec.push_back(3);

	myIterator ft_it = ftvec.begin();
	stdIterator std_it = stdvec.begin();

	ft_it += 1;
	std_it += 1;

	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	ft_ret = ftvec.erase(ft_it);
	std_ret = stdvec.erase(std_it);
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	std::cout << "*** return values ***\n";
	std::cout << *ft_ret << " " << *std_ret << std::endl;

	ftvec.push_back(4);
	ftvec.push_back(5);
	ftvec.push_back(6);
	stdvec.push_back(4);
	stdvec.push_back(5);
	stdvec.push_back(6);

	myIterator b = ftvec.begin() + 2;
	stdIterator b2 = stdvec.begin() + 2;
	myIterator e = ftvec.end() - 1;
	stdIterator e2 = stdvec.end() - 1;
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	ft_ret = ftvec.erase(b, e);
	std_ret = stdvec.erase(b2, e2);
	std::cout << "*** return values ***\n";
	std::cout << *ft_ret << " " << *std_ret << std::endl;
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	std::vector<int> vec3(9, 1);
	ft::vector<int> vec4(9, 1);
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec4);
	printVecElements(vec3);
	printVecElements(vec4);
	vec3.erase(vec3.begin(), vec3.end());
	vec4.erase(vec4.begin(), vec4.end());
	printVecElements(vec3);
	printVecElements(vec4);
	printSizeAndCapacity(vec3);
	printSizeAndCapacity(vec4);
	{
		std::cout << "********\n" << std::endl;
		stdIterator std_ret;
		myIterator ft_ret;
		ft::vector<int> ft_vec;
		for ( size_t i = 1; i <= 10; i++ )
			ft_vec.push_back(i);
		std::vector<int> std_vec;
		for ( size_t i = 1; i <= 10; i++ )
			std_vec.push_back(i);
		printSizeAndCapacity(ft_vec);
		printSizeAndCapacity(std_vec);
		printVecElements(ft_vec);
		printVecElements(std_vec);
		ft_ret = ft_vec.erase( ft_vec.begin() + 5);
		std_ret = std_vec.erase( std_vec.begin() + 5);
		printVecElements(ft_vec);
		printVecElements(std_vec);
		printSizeAndCapacity(ft_vec);
		printSizeAndCapacity(std_vec);
		std::cout << "it: " << *ft_ret << std::endl;
		std::cout << "it: " << *std_ret << std::endl;
		ft_vec.erase(ft_ret);
		std_vec.erase(std_ret);
		printVecElements(ft_vec);
		printVecElements(std_vec);
		printSizeAndCapacity(ft_vec);
		printSizeAndCapacity(std_vec);
	}
}

void	testing_resize( void )
{
	ft::vector<int> ftvec(5, 2);
	std::vector<int> stdvec(5, 2);

	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	stdvec.resize( 0, 10 );
	ftvec.resize( 0, 10 );
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	stdvec.resize( 6, 10 );
	ftvec.resize( 6, 10 );
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
	stdvec.resize( 7, 8 );
	ftvec.resize( 7, 8 );
	printSizeAndCapacity(ftvec);
	printSizeAndCapacity(stdvec);
	printVecElements(ftvec);
	printVecElements(stdvec);
}

void	testing_assign2( void )
{
	// std::vector<int> std_vec(10, 100);
	// ft::vector<int> my_vec(10, 100);
	std::vector<int> range;
	range.push_back(1);
	range.push_back(2);
	range.push_back(3);
	range.push_back(4);
	// std_vec.assign(range.begin(), range.end());
	// my_vec.assign(range.begin(), range.end());
	// printSizeAndCapacity(std_vec);
	// printSizeAndCapacity(my_vec);
	// printVecElements(std_vec);
	// printVecElements(my_vec);
	// std::cout << "*************\n";
	// std::vector<int> std_vec2;
	// std_vec2.push_back(10);
	// std_vec2.push_back(20);
	// std_vec2.push_back(30);
	// ft::vector<int> my_vec2;
	// std_vec2.push_back(10);
	// std_vec2.push_back(20);
	// std_vec2.push_back(30);
	// std::vector<int> range2;
	// range2.push_back(1);
	// range2.push_back(2);
	// range2.push_back(3);
	// range2.push_back(4);
	// std_vec2.assign(range2.begin(), range2.end());
	// my_vec2.assign(range2.begin(), range2.end());
	// printSizeAndCapacity(std_vec2);
	// printSizeAndCapacity(my_vec2);
	// printVecElements(std_vec2);
	// printVecElements(my_vec2);
	std::cout << "*************\n";
	std::vector<int> std_vec;
	ft::vector<int> my_vec;
	std_vec.push_back(10);
	std_vec.push_back(20);
	std_vec.push_back(30);
	my_vec.push_back(10);
	my_vec.push_back(20);
	my_vec.push_back(30);
	std_vec.assign(3, 42);
	my_vec.assign(3, 42);
	printSizeAndCapacity(std_vec);
	printSizeAndCapacity(my_vec);
	printVecElements(std_vec);
	printVecElements(my_vec);
}

void	testing_iterators( void )
{
	std::vector<std::string> vec;
	vec.push_back("say my name");
	vec.push_back("Heisenberg");
	vec.push_back("you're god damn right");
	ft::vector<std::string> ftvec;
	ftvec.push_back("say my name");
	ftvec.push_back("Heisenberg");
	ftvec.push_back("you're god damn right");
	std::vector<std::string>::iterator it = vec.begin();
	std::vector<std::string>::const_iterator const_it = vec.begin() + 3;
	ft::vector<std::string>::iterator ft_it = ftvec.begin();
	ft::vector<std::string>::const_iterator ft_const_it = ftvec.begin() + 3;

	std::cout << "iterators" << std::endl;
	std::cout << *it << std::endl;
	std::cout << *ft_it << std::endl;
	std::cout << "const iterators" << std::endl;
	std::cout << *const_it << std::endl;
	std::cout << *ft_const_it << std::endl;
	--const_it;
	--ft_const_it;
	++it;
	++ft_it;

	std::cout << "iterators" << std::endl;
	std::cout << *it << std::endl;
	std::cout << *ft_it << std::endl;
	std::cout << "const iterators" << std::endl;
	std::cout << *const_it << std::endl;
	std::cout << *ft_const_it << std::endl;

	--it;
	--ft_it;

	std::cout << "iterators" << std::endl;
	std::cout << *( 2 + it ) << std::endl;
	std::cout << *( 2 + ft_it ) << std::endl;
	std::cout << "const iterators" << std::endl;
	std::cout << *(const_it + 1) << std::endl;
	std::cout << *(ft_const_it + 1) << std::endl;
	
}

int	main( void )
{
	std::vector<int> vec;
	for ( size_t i = 1; i <= 10; i++ )
		vec.push_back(i);
	ft::vector<int> ftvec;
	for ( size_t i = 1; i <= 10; i++ )
		ftvec.push_back(i);
	std::reverse_iterator<std::vector<int>::iterator > it = vec.rbegin();
	ft::reverse_iterator<ft::vector<int>::iterator > ft_it = ftvec.rbegin();
	std::cout << "std it: " << *(it + 5) << std::endl;
	std::cout << "my it: " << *(ft_it + 5) << std::endl;
	std::cout << "std it: " << *(3 + it) << std::endl;
	std::cout << "my it: " << *(3 + ft_it) << std::endl;
	// testing_vec_constructors();
	// testing_erase();
	// testing_iterator_traits();
	// testing_push_back();
	// testing_assign();
	// testing_assign2();
	// testing_insert();
	// testing_iterators();
	// testing_resize();
	// testing_reverse_iterator();
	// testing_algorithm();
	// testing_utility();
	// testing_relational_op();


	// std::cout << empty[0] << std::endl;
}