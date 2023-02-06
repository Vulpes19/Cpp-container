/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 15:21:47 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int	main( void )
{
	ft::vector<char> vec2(3, 'a');
	std::vector<char> og_vec2(3, 'a');
	ft::vector<int> empty;
	std::vector<int> og_empty;

	empty.push_back(1);
	og_empty.push_back(1);
	std::cout << empty.back() << " " << empty.capacity() << " " << empty.size() << std::endl;
	std::cout << og_empty.back() << " " << og_empty.capacity() << " " << og_empty.size() << std::endl;

	vec2.push_back('b');
	og_vec2.push_back('b');
	std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	vec2.push_back('c');
	og_vec2.push_back('c');
	std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	vec2.push_back('d');
	og_vec2.push_back('d');
	std::cout << vec2.back() << " " << vec2.capacity() << " " << vec2.size() << std::endl;
	std::cout << og_vec2.back() << " " << og_vec2.capacity() << " " << og_vec2.size() << std::endl;
	
	system("leaks test_vector");
	// std::cout << empty[0] << std::endl;
}