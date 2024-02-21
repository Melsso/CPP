/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:13:44 by smallem           #+#    #+#             */
/*   Updated: 2024/02/05 13:12:43 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Extra.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* dog = new Dog();
	std::cout << std::endl;
    const Animal* cat = new Cat();
	std::cout << std::endl;

    delete dog;
	std::cout << std::endl;

    delete cat;
	std::cout << std::endl;

    std::cout << "----------------------------" << std::endl;
	Dog ogDog;
    {
    	std::cout << std::endl;
	    Dog dog1 = ogDog;
		ogDog.getBrain()->setIdea(0, "Hello");
		std::cout << "Copy : " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Initial: " << ogDog.getBrain()->getIdea(0) << std::endl;
		Dog tmp = ogDog;
		ogDog.getBrain()->setIdea(1, "World");
		std::cout << "Copy0 : " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy1 : " << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << "Initial: " << ogDog.getBrain()->getIdea(0) << std::endl;

		std::cout << "Copy0 : " << dog1.getBrain()->getIdea(1) << std::endl;
		std::cout << "Copy1 : " << tmp.getBrain()->getIdea(1) << std::endl;
		std::cout << "Initial: " << ogDog.getBrain()->getIdea(1) << std::endl;

		ogDog.getBrain()->setIdea(-1, "hi");
		ogDog.getBrain()->setIdea(101, "hi");
	}
	std::cout << "----------------------------" << std::endl;

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
        delete animals[i];
		std::cout << std::endl;
	}
    return 0;
}
