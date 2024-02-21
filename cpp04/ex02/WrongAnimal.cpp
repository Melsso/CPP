/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:53:00 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:15:47 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "Random WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	if (this != &cp)
		this->setType(cp.getType());
}
		
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &member) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal making wrong sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}
