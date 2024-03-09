/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:24:07 by smallem           #+#    #+#             */
/*   Updated: 2024/01/25 17:47:45 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "No input file specified: ./btc <file>" << std::endl;
	else {
		BitcoinExchange btc(argv[1]);
	}
}
