/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:08:12 by smallem           #+#    #+#             */
/*   Updated: 2023/12/21 21:27:44 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	FragTrapA("John");
	FragTrap	FragTrapB("Simon");
	std::cout << std::endl;
	std::cout << FragTrapA << FragTrapB << std::endl;

	FragTrapA.attack("Simon");
	FragTrapB.takeDamage(FragTrapA.getAd());
	std::cout << std::endl;

	std::cout << FragTrapA << FragTrapB << std::endl;

	FragTrapB.beRepaired(5);
	std::cout << std::endl;
	std::cout << FragTrapA << FragTrapB << std::endl;

	FragTrapB.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
