/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:08:12 by smallem           #+#    #+#             */
/*   Updated: 2023/12/22 11:33:36 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{

	ScavTrap	ScavTrapA("Robot A");
	ScavTrap	ScavTrapB("Robot B");

	std::cout << std::endl;

	std::cout << ScavTrapA << ScavTrapB << std::endl;

	ScavTrapA.attack("Robot B");
	ScavTrapB.takeDamage(ScavTrapA.getAd());

	std::cout << std::endl;
	std::cout << ScavTrapA << ScavTrapB << std::endl;

	ScavTrapB.beRepaired(5);
	
	std::cout << std::endl;
	std::cout << ScavTrapA << ScavTrapB << std::endl;
	
	ScavTrapB.guardGate();
	std::cout << std::endl;

	return (0);
}
