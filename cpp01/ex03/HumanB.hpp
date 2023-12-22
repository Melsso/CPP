/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:10:13 by smallem           #+#    #+#             */
/*   Updated: 2023/10/14 18:51:36 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *arme;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& arme);
		void attack(void);
};

#endif
