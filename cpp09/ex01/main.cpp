/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:59:52 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:37:47 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error, Invalid number of arguments" << std::endl;
		return 0;
	}
	std::string line(argv[1]);
	RPN RPN(line);
	return 0;
}
