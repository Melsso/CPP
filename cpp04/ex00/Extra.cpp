/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extra.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:18:06 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 10:39:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Extra.hpp"

//////////CAT///////////
Cat::Cat(void) {
	std::cout << "Cat constructor called" << std::endl;
	this->setType("Cat");
}

Cat::~Cat(void) {
	std::cout << "Cat deconstructor called" << std::endl;	
}

Cat::Cat(const Cat &cp) : Animal(cp) {
	std::cout << "Cat copy constructor called" << std::endl;	
	this->setType(cp.getType());
}

Cat &Cat::operator=(const Cat &member) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meows" << std::endl;
}
//////////DOG///////////
Dog::Dog(void) {
	std::cout << "Dog constructor called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog(void) {
	std::cout << "Dog deconstructor called" << std::endl;
}
	
Dog::Dog(const Dog &cp) : Animal(cp) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->setType(cp.getType());
}

Dog &Dog::operator=(const Dog &member) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &member)
		this->setType(member.getType());
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Barks" << std::endl;
}
