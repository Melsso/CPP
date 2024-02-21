/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:18 by smallem           #+#    #+#             */
/*   Updated: 2024/01/15 12:56:00 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	this->type = "Random animal";
	std::cout << "Animal constructor called" << std::endl;
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
		setType(member.getType());
	return *this;
}

void Animal::makeSound(void) const {
	std::cout << "Animal making noise" << std::endl;
}
