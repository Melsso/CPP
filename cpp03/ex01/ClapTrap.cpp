/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:24:42 by smallem           #+#    #+#             */
/*   Updated: 2023/12/22 11:58:59 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("nameless"), hp(10), energy(10), ad(0) {
	std::cout << "Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), energy(10), ad(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->setName(copy.getName());
	this->setAd(copy.getAd());
	this->setEnergy(copy.getEnergy());
	this->setHp(copy.getHp());
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cp) {
	std::cout << "Assignment operator call" << std::endl;
	this->name = cp.name;
	this->hp = cp.hp;
	this->energy = cp.energy;
	this->ad = cp.ad;
	return *this;
}
////////SETTERS AND GETTERS////////

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setEnergy(int energy) {
	if (energy >= 0)
		this->energy = energy;
	else
		std::cout << "Amount cannot be negative!" << std::endl;
}

void ClapTrap::setHp(int hp) {
	if (hp >= 0)
		this->hp = hp;
	else
		std::cout << "Amount cannot be negative!" << std::endl;
}

void ClapTrap::setAd(int ad) {
	
	if (ad >= 0)
		this->ad = ad;
	else
		std::cout << "Amount cannot be negative!" << std::endl;
}

std::string ClapTrap::getName(void) const {
	return this->name;
}

int ClapTrap::getHp(void) const {
	return this->hp;
}

int ClapTrap::getEnergy(void) const {
	return this->energy;
}

int ClapTrap::getAd(void) const {
	return this->ad;
}

////////MEMBER FUNCTIONS////////

void ClapTrap::attack(const std::string &target) {
	if (this->getEnergy() > 0 && this->getHp() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getAd() << " points of damage!" << std::endl;
		this->setEnergy(this->getEnergy() - 1);	
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has no hp/energy left!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHp() > 0)
	{
		unsigned int var;
		if ((unsigned int)this->getHp() < amount)
			var = (unsigned int)this->getHp();
		else
			var = amount;
		std::cout << "ClapTrap " << this->getName() << " has lost " << amount << " health points!" << std::endl;
		this->setHp(this->getHp() - var);
	}
	else
		std::cout << "ClapTrap " << this->getName() << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergy() > 0 && this->getHp() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has recovered " << amount << " health points!" << std::endl;
		if (this->getHp() + amount > 2147483647)
			this->setHp(2147483647);
		else
			this->setHp(this->getHp() + amount);
		this->setEnergy(this->getEnergy() - 1);	
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has no hp/energy left!" << std::endl;
}

////////OTHER FUNCTIONS////////

std::ostream &operator<<(std::ostream &out, ClapTrap &member) {
	out << "Name: " << member.getName() << " HP: " << member.getHp() << " AD: " << member.getAd() << " Energy: " << member.getEnergy() << std::endl;
	return (out);
}
