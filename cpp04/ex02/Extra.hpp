/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:13:54 by smallem           #+#    #+#             */
/*   Updated: 2024/01/15 12:32:37 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
# define EXTRA_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog(void);
		virtual ~Dog(void);		
		Dog(const Dog &cp);

		void setBrain(Brain *brain);
		Brain *getBrain(void) const;
		Dog &operator=(const Dog &member);
		virtual void makeSound(void) const;
};

class Cat : public Animal {
	private:
		Brain *brain;
	public:
		Cat(void);
		virtual ~Cat(void);		
		Cat(const Cat &cp);

		void setBrain(Brain *brain);
		Brain *getBrain(void) const;
		Cat &operator=(const Cat &member);
		virtual void makeSound(void) const;		
};

#endif
