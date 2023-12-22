/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:33 by smallem           #+#    #+#             */
/*   Updated: 2023/10/10 18:53:21 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie *horde;

	horde = zombieHorde(5, "ZoMbIe");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
