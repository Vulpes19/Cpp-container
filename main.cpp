/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/10 15:52:09 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

template<typename T>
void	printVecElements( ft::vector<T> &vec )
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

template<typename T>
void	printVecElements( std::vector<T> &vec )
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

int	main( void )
{
	/* testing push_back*/
	// ft::vector<char> vec2(3, 'a');
	// std::vector<char> og_vec2(3, 'a');
	// ft::vector<int> empty;
	// std::vector<int> og_empty;

	// empty.push_back(1);
	// og_empty.push_back(1);
	// std::cout << empty.back() << " " << empty.capacity() << " " << empty.size() << std::endl;
	// std::cout << og_empty.back() << " " << og_empty.capacity() << " " << og_empty.size() << std::endl;

	// vec2.push_back('b');
	// og_vec2.push_back('b');
	// std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	// std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	// vec2.push_back('c');
	// og_vec2.push_back('c');
	// std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	// std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	// vec2.push_back('d');
	// og_vec2.push_back('d');
	// std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	// std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	
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
	

	std::vector<int> vec(1, 1);
	ft::vector<int> vec2(1, 1);
	vec.push_back(2);
	vec2.push_back(2);
	// std::vector<int>::iterator it = vec.begin();
	// ft::vector<int>::iterator it2 = vec2.begin();

	for ( std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << *it << std::endl;
	// ++it;
	// ++it2;
	for ( ft::vector<int>::iterator it2 = vec2.begin(); it2 < vec2.end(); it2++)
		std::cout << *it2 << std::endl;
	system("leaks test_vector");
	// std::cout << empty[0] << std::endl;
}