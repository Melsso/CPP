/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:15:35 by smallem           #+#    #+#             */
/*   Updated: 2023/10/10 16:26:18 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie stack("stack1");
	Zombie *heap = newZombie("heap");

	randomChump("stack2");
	stack.announce();
	heap->announce();
	delete heap;
	return (0);
}
