/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:11:24 by smallem           #+#    #+#             */
/*   Updated: 2023/10/14 18:28:11 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon& arme;

	public:
		~HumanA(void);
		HumanA(std::string name, Weapon& arme);
		void attack(void);
};

#endif
