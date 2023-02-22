/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/22 10:10:35 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "TypeTraits.hpp"
#include "Utility.hpp"
#include <vector>
#include <typeinfo>
#include <time.h>
#include <iostream>

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
	std::vector<int> vec(5, 1);
	ft::vector<int> ftvec(5, 1);
	std::vector<int> c(4, 9);

	stdIterator it = vec.begin();
	it++;
	myIterator it2 = ftvec.begin();
	it2++;
	stdIterator begin = c.begin();
	stdIterator end = c.end();
	printSizeAndCapacity(vec);
	printSizeAndCapacity(ftvec);
	printVecElements(vec);
	printVecElements(ftvec);
	vec.insert( it, begin, end);
	ftvec.insert( it2, begin, end);
	printSizeAndCapacity(vec);
	printSizeAndCapacity(ftvec);
	printVecElements(vec);
	printVecElements(ftvec);

	it = vec.begin() + 2;
	it2 = ftvec.begin() + 2;
	vec.insert( it, 2, -9);
	ftvec.insert( it2, 2, -9);
	printSizeAndCapacity(vec);
	printSizeAndCapacity(ftvec);
	printVecElements(vec);
	printVecElements(ftvec);

	it = vec.begin() + 1;
	it2 = ftvec.begin() + 1;
	vec.insert( it, 42);
	ftvec.insert( it2, 42);
	printSizeAndCapacity(vec);
	printSizeAndCapacity(ftvec);
	printVecElements(vec);
	printVecElements(ftvec);
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
	p.swap(pc);
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

int	main( void )
{
	// testing_vec_constructors();
	// testing_erase();
	// testing_iterator_traits();
	// testing_push_back();
	testing_assign();
	// testing_insert();
	// testing_resize();
	// testing_reverse_iterator();
	// testing_algorithm();
	// testing_utility();
	// testing_relational_op();

	system("leaks test_vector");


	// std::cout << empty[0] << std::endl;
}