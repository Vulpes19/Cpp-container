/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:10 by abaioumy          #+#    #+#             */
/*   Updated: 2023/02/06 13:58:58 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int	main( void )
{
	ft::vector<int> empty;
	ft::vector<int> vec1(3, 1);
	// ft::vector<int> empty = vec1;
	empty = vec1;
	std::cout << empty[0] << std::endl;
	std::vector<int> empty1;
	system("leaks test_vector");
	// std::cout << empty[0] << std::endl;
}