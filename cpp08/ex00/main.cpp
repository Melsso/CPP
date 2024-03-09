/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:50:03 by smallem           #+#    #+#             */
/*   Updated: 2024/01/19 15:16:53 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
    try {
		std::vector<int> 			myVector;
		std::vector<int>::iterator 	iter;
		for (int i = 0; i < 7; i++)
			myVector.push_back(i);
		
		easyfind(myVector, 3);

		easyfind(myVector, 8);
    }
	catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }
	return 0;
}

