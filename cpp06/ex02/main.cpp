/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:23:58 by smallem           #+#    #+#             */
/*   Updated: 2024/03/07 16:16:40 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base *generate(void) {
	int					n;
	std::random_device 	rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(1, 3);
	n = distribution(gen);
	switch(n) {
		case 1:
			std::cout << "Generated Object type A" << std::endl;
			return (new A());
		case 2:
			std::cout << "Generated Object type B" << std::endl;
			return (new B());
		case 3:
			std::cout << "Generated Object type C" << std::endl;
			return (new C());
		default:
			std::cout << "Failed to generate an object!" << std::endl;
			return (NULL);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Objectptr is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Objectptr is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Objectptr is of type C" << std::endl;
	else
		std::cout << "Failed to identify objectptr" << std::endl;
}

void identify(Base& p) {
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "Objectref is of type A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}	
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "Objectref is of type B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "Objectref is of type C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {
        std::cout << "Failed to cast to a known type" << std::endl;
	}
}

int	main(void) {
	Base *random;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;
	
	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	random = generate();
	identify(random);
	identify(*random);
	delete random;
	std::cout << std::endl;

	Base	rnd;
	identify(&rnd);
	identify(rnd);
}
