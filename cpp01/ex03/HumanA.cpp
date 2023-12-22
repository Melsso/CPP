/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:44:44 by smallem           #+#    #+#             */
/*   Updated: 2023/10/14 18:32:00 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(void)
{
	
}

HumanA::HumanA(std::string name, Weapon &arme) : name(name), arme(arme)
{
	
}

void HumanA::attack(void) {
	std::cout << this->name << " attacks with his " << this->arme.getType() << std::endl;
}
