/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:39:59 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 13:34:34 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
	// Shrub 145s 137e
	// Pardon 25s 5e
	// Robotomy 72s 45e
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Bureaucrat *b = new Bureaucrat("Bob", 140);
	Bureaucrat *b1 = new Bureaucrat("Boss", 1);
	// AForm *f = new AForm();
	ShrubberyCreationForm *shrb = new ShrubberyCreationForm("Shrubbery");
	PresidentialPardonForm *ppf = new PresidentialPardonForm("PardonForm");
	RobotomyRequestForm *rrf = new RobotomyRequestForm("Robotomy");
	std::cout << std::endl;
		
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << *b << *b1 << *shrb << *ppf << *rrf;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	// bob tries to sign and execute, sign should work but not execution
	try 
	{
		b->signForm(*shrb);
		// shrb->execute(*b);
		//boss executes it should work 
		shrb->execute(*b1); 
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << *shrb;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	// executing the remaining forms
	try
	{
		// b->signForm(*ppf); // should fail bob cant sign
		// ppf->execute(*b);
		b1->signForm(*ppf);
		ppf->execute(*b1);		
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << *ppf;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	try
	{
		// b->signForm(*rrf);
		// rrf->execute(*b);
		b1->signForm(*rrf);
		rrf->execute(*b1);	
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << *rrf;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	delete rrf;
	delete ppf;
	delete shrb;
	delete b;
	delete b1;
}
