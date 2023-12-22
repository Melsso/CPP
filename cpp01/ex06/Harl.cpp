/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:40:37 by smallem           #+#    #+#             */
/*   Updated: 2023/10/13 16:44:54 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	
}

Harl::~Harl(void) {

}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;	
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level, std::string filter) {
	std::string list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i;
	for (i = 0; i < 4; i++) {
		if (list[i] == level)
			break ;
	}
	int j;
	for (j = 0; j < 4; j++) {
		if (list[j] == filter)
			break ;
	}
	if (j == 4)
		std::cout << "Bad filter level!" << std::endl;
	if (i >= j)
	{
		switch(i) {
			case 0:
				this->debug();
				break ;
			case 1:
				this->info();
				break ;
			case 2:
				this->warning();
				break ;
			case 3:
				this->error();
				break ;
		}
	}
}
