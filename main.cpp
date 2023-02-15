/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/15 15:39:28 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "TypeTraits.hpp"
#include <vector>
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

// void	testing_assign( void )
// {
// 	clock_t start, stop;
// 	std::vector<int> vec(4, 1);
// 	std::vector<int> vec3(3, 9);
// 	ft::vector<int> vec2(3, 9);
// 	stdIterator begin = vec.begin();
// 	myIterator begin2 = vec2.begin();
// 	stdIterator end = vec.end();
// 	myIterator end2 = vec2.end();
// 	// end -= 2;
// 	// end2 -= 2;
// 	printSizeAndCapacity(vec3);
// 	printSizeAndCapacity(vec2);
// 	printVecElements(vec3);
// 	start = clock();
// 	vec3.assign( begin, end );
// 	stop = clock();
// 	printTime(start, stop, "std");
// 	printVecElements(vec3);
// 	printVecElements(vec2);
// 	start = clock();
// 	vec2.assign( begin, end );
// 	stop = clock();
// 	printTime(start, stop, "ft");
// 	printVecElements(vec2);
// 	printSizeAndCapacity(vec3);
// 	printSizeAndCapacity(vec2);
// 	std::cout << "**************\n";
// 	std::cout << "**************\n";
// 	std::cout << "**************\n";
// 	printSizeAndCapacity(vec3);
// 	printSizeAndCapacity(vec2);
// 	printVecElements(vec3);
// 	start = clock();
// 	vec3.assign( 10, -1 );
// 	stop = clock();
// 	printTime(start, stop, "std");
// 	printVecElements(vec3);
// 	printVecElements(vec2);
// 	start = clock();
// 	vec2.assign( 10, -1 );
// 	stop = clock();
// 	printTime(start, stop, "ft");
// 	printVecElements(vec2);
// 	printSizeAndCapacity(vec3);
// 	printSizeAndCapacity(vec2);
// }

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
	printVecElements(vec);
	printVecElements(ftvec);
	vec.insert(it, begin, end);
	ftvec.insert(it2, begin, end);
	printVecElements(vec);
	printVecElements(ftvec);
}

int	main( void )
{
	// testing_push_back();
	// testing_assign();
	// testing_insert();

	std::cout << ft::is_integral<int>::value << std::endl; 
	// printSizeAndCapacity(vec);
	// printSizeAndCapacity(og_vec);
	// vec.push_back('b');
	// og_vec.push_back('b');
	// vec.push_back('c');
	// og_vec.push_back('c');
	// vec.push_back('d');
	// og_vec.push_back('d');
	// printSizeAndCapacity(vec);
	// printSizeAndCapacity(og_vec);
	/*testing resize and capacity*/
	// try
	// {
	// 	ft::vector<int> vec1(3, 1);
	// 	std::vector<int> vec(3, 1);
	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// 	std::cout << "*****" << std::endl;
	// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	// 	vec.resize(2, 3);
	// 	for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << vec[i] << std::endl;
	// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	// 	std::cout << "------------------" << std::endl;
	// 	for (size_t i = 0; i < vec1.size(); i++)
	// 		std::cout << vec1[i] << std::endl;
	// 	std::cout << "*****" << std::endl;
	// 	std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
	// 	vec1.resize(2, 3);
	// 	for (size_t i = 0; i < vec1.size(); i++)
	// 		std::cout << vec1[i] << std::endl;
	// 	std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
	// 	std::cout << "*****" << std::endl;
	// 	vec.clear();
	// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	// 	vec1.clear();
	// 	std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	/*testing front, pop_back*/
	// std::vector<int> vec(1, 1);
	// ft::vector<int> vec2(3, 2);
	// ft::vector<int> vec3(2, 1);
	// ft::vector<int> vec1(1, 1);

	// std::cout << "vec2 size: " << vec2.size() << std::endl;
	// std::cout << "vec3 size: " << vec3.size() << std::endl;
	// std::cout << "vec2 capacity: " << vec2.capacity() << std::endl;
	// std::cout << "vec3 capacity: " << vec3.capacity() << std::endl;
	// printVecElements(vec2);
	// printVecElements(vec3);
	// vec2.swap(vec3);
	// std::cout << "vec2 size: " << vec2.size() << std::endl;
	// std::cout << "vec3 size: " << vec3.size() << std::endl;
	// std::cout << "vec2 capacity: " << vec2.capacity() << std::endl;
	// std::cout << "vec3 capacity: " << vec3.capacity() << std::endl;
	// printVecElements(vec2);
	// printVecElements(vec3);
	// try
	// {
	// 	std::cout << vec.front() << std::endl;
	// 	std::cout << vec1.front() << std::endl;
	// 	vec.push_back(2);
	// 	vec1.push_back(2);
	// 	std::cout << vec.back() << " " << vec1.back() << std::endl;
	// 	vec.pop_back();
	// 	vec1.pop_back();
	// 	std::cout << vec.back() << " " << vec1.back() << std::endl;
	// 	std::cout << "std::vector capacity: " << vec.capacity() << std::endl;
	// 	std::cout << "ft::vector capacity: " << vec1.capacity() << std::endl;
	// 	vec.reserve(10);
	// 	vec1.reserve(10);
	// 	std::cout << "std::vector capacity: " << vec.capacity() << std::endl;
	// 	std::cout << "ft::vector capacity: " << vec1.capacity() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	

	// clock_t start, end;
	// std::vector<int> vec(8, 1);
	// ft::vector<int> vec2(8, 1);
	// std::vector<int> vec3(8, 4);
	// ft::vector<int> vec4(8, 4);
	// vec.push_back(2);
	// vec2.push_back(2);
	// // stdIterator begin = vec.begin();
	// // myIterator begin2 = vec2.begin();
	// stdIterator first = vec.begin();
	// myIterator first2 = vec2.begin();
	// stdIterator last = vec.end();
	// myIterator last2 = vec2.end();
	// stdIterator tmp;
	// myIterator tmp2;
	// // std::vector<int>::iterator end = vec.end();
	// // ft::vector<int>::iterator end2 = vec2.end();

	// first++;
	// first2++;
	// // std::cout << *first << " " << *first2 << std::endl;
	// last--;
	// last--;
	// last2--;
	// last2--;
	// // printSizeAndCapacity(vec2);
	// // printSizeAndCapacity(vec);
	// // printVecElements(vec);
	// // printVecElements(vec2);
	// // vec.insert( begin, 3, 9 );
	// // vec2.insert( begin2, 3, 9 );
	// // printSizeAndCapacity(vec2);
	// // printSizeAndCapacity(vec);
	// printVecElements(vec);
	// printVecElements(vec2);
	// start = clock();
	// tmp = vec.erase(first, last);
	// end = clock();
	// printTime(start, end);
	// start = clock();
	// tmp2 = vec2.erase(first2, last2);
	// end = clock();
	// printTime(start, end);
	// printVecElements(vec);
	// printVecElements(vec2);
	// // printSizeAndCapacity(vec);
	//testing assign
	system("leaks test_vector");


	// std::cout << empty[0] << std::endl;
}