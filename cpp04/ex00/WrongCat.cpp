/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:26:45 by smallem           #+#    #+#             */
/*   Updated: 2023/12/23 12:32:49 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->setType(cp.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &member) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;	
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat making noise" << std::endl;
}
