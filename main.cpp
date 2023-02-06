/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 14:26:30 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int	main( void )
{
	ft::vector<int> empty;
	ft::vector<int> vec1(3, 1);
	ft::vector<char> vec2(3, 'a');
	// ft::vector<int> empty = vec1;
	std::cout << empty.empty() << std::endl;
	empty = vec1;
	std::cout << empty.at(0) << std::endl;
	std::cout << vec2.empty() << std::endl;
	std::vector<int> empty1;
	system("leaks test_vector");
	// std::cout << empty[0] << std::endl;
}