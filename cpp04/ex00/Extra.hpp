/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:13:54 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 10:38:39 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
# define EXTRA_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		virtual ~Dog(void);		
		Dog(const Dog &cp);

		Dog &operator=(const Dog &member);
		virtual void makeSound(void) const;		
};

class Cat : public Animal {
	public:
		Cat(void);
		virtual ~Cat(void);		
		Cat(const Cat &cp);

		Cat &operator=(const Cat &member);
		virtual void makeSound(void) const;		
};

#endif
