/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:18 by smallem           #+#    #+#             */
/*   Updated: 2023/12/23 12:34:00 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(const Animal &cp) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->setType(cp.getType());
}

Animal::~Animal(void) {
	std::cout<< "Animal deconstructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

Animal &Animal::operator=(const Animal &member) {
	std::cout << "Animal operator assignment called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "Animal making noise" << std::endl;
}
