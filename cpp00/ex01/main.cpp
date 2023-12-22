/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:31:40 by smallem           #+#    #+#             */
/*   Updated: 2023/12/11 15:41:46 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool isNumber(std::string input) {

	if (input.length() != 1 || !std::isdigit(input[0])
		|| input[0] < '0' || input[0] > '8')
		return false;
	return true;
}

int main(void) {
	PhoneBook pb;
	std::string	input;
	pb.n = 0;

	while (1) {
		std::cout << "Cmd list: ADD-SEARCH-EXIT" <<std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			if (pb.n == 8)
				pb.rotate();
			if (!pb.cl[pb.n].fill_cont())
				continue ;
			if (pb.n < 8)
				pb.n++;
		}
		else if (input == "SEARCH") {
			if (pb.n != 0) {
				for (int i = 0; i < pb.n; i++)
					pb.cl[i].display_cont(i);
			}
			else {
				std::cout << "No contacts yet!" << std::endl;
				continue ;
			}
			int ind;
			std::string	sind;
			std::cout << "Which index?" << std::endl;
			std::cin >> sind;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (!isNumber(sind))
			{
				std::cout << "Bad index!" << std::endl;
				std::cin.clear();
				continue ;
			}
			ind = std::stoi(sind);
			if (ind >= pb.n || ind < 0) {
				std::cout << "Bad index!" << std::endl;
				std::cin.clear();
				continue ;
			}
			else
				pb.cl[ind].display_all();
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Unknown command!" << std::endl;
	}
}
