/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:49:17 by smallem           #+#    #+#             */
/*   Updated: 2023/10/10 17:17:38 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;
	public:	
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
