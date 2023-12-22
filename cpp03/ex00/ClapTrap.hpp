/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:16:35 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:51:02 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int	hp;
		int energy;
		int ad;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &cp);
	
		void setName(std::string name);
		void setEnergy(int energy);
		void setHp(int hp);
		void setAd(int ad);
		std::string getName(void) const;
		int getHp(void) const;
		int getEnergy(void) const;
		int getAd(void) const;
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

std::ostream &operator<<(std::ostream &out, ClapTrap &member);
#endif
