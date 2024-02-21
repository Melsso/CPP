/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:13:44 by smallem           #+#    #+#             */
/*   Updated: 2024/02/05 12:49:54 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Extra.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nType is: " << dog->getType() << std::endl;
	std::cout << "Type is: " << cat->getType() << "\n" << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;
	
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << std::endl;
	
	WrongAnimal wrongAnimal;
	std::cout << wrongAnimal.getType() << std::endl;
	wrongAnimal.makeSound();
	std::cout << std::endl;
	
	delete wrongCat;
	return (0);
}
