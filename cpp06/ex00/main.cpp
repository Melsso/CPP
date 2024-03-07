/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:33:47 by smallem           #+#    #+#             */
/*   Updated: 2024/03/06 18:22:29 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Invalid usage! ./ScalarConv [argument]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
