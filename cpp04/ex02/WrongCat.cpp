/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:26:45 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:16:19 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "Random WrongCat";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &member) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;	
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat making wrong noise" << std::endl;
}
