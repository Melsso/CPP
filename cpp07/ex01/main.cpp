/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:28:33 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 16:46:44 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "inc.hpp"

int main(void) {
	int			arr[5] = {0, 1, 2, 3, 4};
	char		c[5] = {'h', 'e', 'l', 'l', 'o'};
	std::string mat[5] = {
		"hey",
		"everyone",
		"how's",
		"it",
		"going"
	};

	iter(arr, 5, print_value<int>);
	std::cout << std::endl;

	iter(c, 5, print_value<char>);
	std::cout << std::endl;

	iter(mat, 5, print_value<std::string>);
	std::cout << std::endl;
}
