/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:26:30 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 13:02:51 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &cp) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)cp;
}

Intern &Intern::operator=(const Intern &mem) {
	std::cout << "Intern assignment constructor called" << std::endl;
	(void)mem;
	return *this;
}

static AForm	*makePresident(const std::string target)
{
	PresidentialPardonForm *ppf = new PresidentialPardonForm(target);
	std::cout << *ppf;
	return ppf;
}

static AForm	*makeRobot(const std::string target)
{
	RobotomyRequestForm *rrf = new RobotomyRequestForm(target);
	std::cout << *rrf;
	return rrf;
}

static AForm	*makeShrubbery(const std::string target)
{
	ShrubberyCreationForm *scf = new ShrubberyCreationForm(target);
	std::cout << *scf;
	return scf;
}

AForm *Intern::makeForm(const std::string form, const std::string target) {
	std::string list[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	AForm *(*all_forms[])(const std::string target) = {&makeShrubbery, &makePresident, &makeRobot};
	for (int i = 0; i < 3; i++)
	{
		if (list[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern could not create the form!" << std::endl;
	return (NULL);
}
