/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:52:59 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 11:15:23 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &cp);
		
		WrongAnimal &operator=(const WrongAnimal &member);
		void makeSound(void) const;
		std::string getType(void) const;
		void setType(std::string type);
};

#endif
