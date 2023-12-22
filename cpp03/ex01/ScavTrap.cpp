/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:31:11 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:54:05 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHp(100);
	this->setAd(20);
	this->setEnergy(50);
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &member) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &member) {
		this->setName(member.getName());
		this->setHp(member.getHp());
		this->setAd(member.getAd());
		this->setEnergy(member.getEnergy());
	}
	return *this;
}
////////////MEMBER FUNCTIONS/////////////
void ScavTrap::attack(std::string const &target) {
	std::cout << this->getName() << " attacked " << target << " and dealt " << this->getAd() << "damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << this->getName() << " is now in gate keeper mode." << std::endl;
}
