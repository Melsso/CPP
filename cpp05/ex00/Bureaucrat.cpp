/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:18:24 by smallem           #+#    #+#             */
/*   Updated: 2023/12/13 16:02:27 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &Name, int grade) : name(Name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(void) : name("default"), grade(2) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat: " << this->getName() << " deconstructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp) : name(cp.getName()), grade(cp.getGrade()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;	
}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &member) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &member) {
		this->setGrade(member.getGrade());
	}
	return *this;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	else
		this->grade = grade;
}

int Bureaucrat::getGrade(void) const {
	return this->grade;
}

const std::string Bureaucrat::getName(void) const {
	return this->name;
}

void Bureaucrat::increment(void) {
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrement(void) {
	this->setGrade(this->getGrade() + 1);
}

const char* Bureaucrat::GradeTooLow::what() const throw() {
	return "Grade is too low";
}

const char* Bureaucrat::GradeTooHigh::what() const throw() {
	return "Grade is too high";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &member) {
	out << member.getName() << ", bureaucrat grade " << member.getGrade() << "." << std::endl;
	return (out);
}
