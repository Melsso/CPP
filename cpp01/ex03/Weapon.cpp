/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:05:00 by smallem           #+#    #+#             */
/*   Updated: 2023/12/12 14:27:05 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon(void){
	std::cout << "The weapon of type " << this->type << " is destroyed" << std::endl;
}

void Weapon::setType(std::string type) {
	this->type = type;
}

const std::string& Weapon::getType(void) {
	return (this->type);
}
