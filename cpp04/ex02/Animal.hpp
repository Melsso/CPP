/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:17 by smallem           #+#    #+#             */
/*   Updated: 2024/01/15 12:58:51 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;
		Animal(void);
	public:
		virtual ~Animal(void);

		std::string getType(void) const;
		void setType(std::string type);
		virtual Animal &operator=(const Animal &member);
		virtual void makeSound(void) const = 0;
};

#endif
