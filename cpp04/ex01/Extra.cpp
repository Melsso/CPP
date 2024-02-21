/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extra.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:18:06 by smallem           #+#    #+#             */
/*   Updated: 2024/02/05 12:53:02 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Extra.hpp"

//////////CAT///////////
Cat::Cat(void) {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat(void) {
	std::cout << "Cat deconstructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Cat::Cat(const Cat &cp) : Animal(cp), brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;	
	if (this != &cp)
	{
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.getBrain());
	}
}

void Cat::setBrain(Brain *brain) {
	this->brain = brain;
}

Brain *Cat::getBrain(void) const {
	return this->brain;
}

Cat &Cat::operator=(const Cat &member) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &member) {
		this->setType(member.getType());
		if (this->brain)
			delete this->brain;
		if (member.brain)
			this->brain = new Brain(*member.getBrain());	
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meows" << std::endl;
}

//////////DOG///////////

Dog::Dog(void) {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void) {
	std::cout << "Dog deconstructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}
	
Dog::Dog(const Dog &cp) : Animal(cp), brain(NULL) {
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &cp)
	{
		this->setType(cp.getType());
		if (this->brain)
			delete this->brain;
		if (cp.brain)
			this->brain = new Brain(*cp.getBrain());	
	}
}

void Dog::setBrain(Brain *brain) {
	this->brain = brain;
}

Brain *Dog::getBrain(void) const {
	return this->brain;
}

Dog &Dog::operator=(const Dog &member) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &member) {
		this->setType(member.getType());
		if (this->brain)
			delete this->brain;
		if (member.brain)
			this->brain = new Brain(*member.getBrain());
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Barks" << std::endl;
}
