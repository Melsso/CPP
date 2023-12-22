/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:49:58 by smallem           #+#    #+#             */
/*   Updated: 2023/10/14 18:53:18 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(void) {

}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->arme = NULL;
}

void HumanB::setWeapon(Weapon& arme) {
	this->arme = &arme;
}

void HumanB::attack(void) {
	if (this->arme)
		std::cout << this->name << " attacks with his " << this->arme->getType() << std::endl;
	else
		std::cout << this->name << " does not have a weapon!" << std::endl;
}
