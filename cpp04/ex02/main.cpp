/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:13:44 by smallem           #+#    #+#             */
/*   Updated: 2024/02/05 13:17:37 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Extra.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* CatsAndDogs[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			CatsAndDogs[i] = new Cat();
		else
			CatsAndDogs[i] = new Dog();
		std::cout << "--------------------------" << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			 dynamic_cast<Cat*>(CatsAndDogs[i])->getBrain()->setIdea(0, "Feed me...");
		else
			 dynamic_cast<Dog*>(CatsAndDogs[i])->getBrain()->setIdea(0, "Lets play fetch!!!");
	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			std::cout << i << ": " <<  dynamic_cast<Cat*>(CatsAndDogs[i])->getType() << " => ";
			dynamic_cast<Cat*>(CatsAndDogs[i])->makeSound();
			std::cout << "Brain: " <<  dynamic_cast<Cat*>(CatsAndDogs[i])->getBrain()->getIdea(0);
			std::cout << std::endl;
		}
		else
		{
			std::cout << i << ": " <<  dynamic_cast<Dog*>(CatsAndDogs[i])->getType() << " => ";
			 dynamic_cast<Dog*>(CatsAndDogs[i])->makeSound();
			std::cout << "Brain: " <<  dynamic_cast<Dog*>(CatsAndDogs[i])->getBrain()->getIdea(0);
			std::cout << std::endl;
		}
	}
	std::cout << "--------------------------" << std::endl;
	for (int i = 0; i < 10; i++) {
		delete CatsAndDogs[i];
		std::cout << "--------------------------" << std::endl;
	}
	// These should not compile!
	// Animal an;
	// Animal an = new Animal();
}
