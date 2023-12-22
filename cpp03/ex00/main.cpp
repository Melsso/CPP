/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:08:12 by smallem           #+#    #+#             */
/*   Updated: 2023/12/22 12:00:59 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ClaptrapA("John");
	ClapTrap	ClaptrapB("Simon");

	ClapTrap	ClapTrapC(ClaptrapA);

	std::cout << std::endl;
	std::cout << ClapTrapC;
	std::cout << ClaptrapA << ClaptrapB << std::endl;

	ClaptrapA.attack("Simon");
	ClaptrapB.takeDamage(ClaptrapA.getAd());

	std::cout << std::endl;
	std::cout << ClaptrapA << ClaptrapB << std::endl;
	
	ClaptrapA.setAd(6);
	ClaptrapA.attack("Simon");
	ClaptrapB.takeDamage(ClaptrapA.getAd());
	ClaptrapA.attack("Simon");
	ClaptrapB.takeDamage(ClaptrapA.getAd());
	ClaptrapA.attack("Simon");
	ClaptrapB.takeDamage(ClaptrapA.getAd());

	std::cout << std::endl;
	std::cout << ClaptrapA << ClaptrapB << std::endl;

	ClaptrapB.beRepaired(5);

	std::cout << std::endl;
	std::cout << ClaptrapA << ClaptrapB << std::endl;

	ClaptrapB.setHp(1);
	ClaptrapB.beRepaired(5);

	ClaptrapA.setHp(-5);
	ClaptrapA.setAd(-5);
	ClaptrapA.setEnergy(-5);

	std::cout << std::endl;
	std::cout << ClaptrapA << ClaptrapB << std::endl;

	return (0);
}
