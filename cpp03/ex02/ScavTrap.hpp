/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:29:49 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:57:30 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
	
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cp);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &member);
		void attack(std::string const &target);
		void guardGate(void);
};

#endif
