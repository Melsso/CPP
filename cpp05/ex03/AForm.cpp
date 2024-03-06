/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:58:27 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:49:13 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default"), signature(false), grade_sig(150), grade_exe(150)
{
	std::cout << "Form default constructor called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exe() < 1)
		throw GradeTooHighException();
	else if (this->getGrade_sig() > 150 || this->getGrade_exe() > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string &Name, bool sig, int g_s, int g_e) : name(Name), signature(sig),
	grade_sig(g_s), grade_exe(g_e)
{
	std::cout << "Form constructor called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exe() < 1)
		throw GradeTooHighException();
	else if (this->getGrade_sig() > 150 || this->getGrade_exe() > 150)
		throw GradeTooLowException();
}

AForm::~AForm(void) 
{
	std::cout << "Form: " << this->getName() << " deconstructor called" << std::endl;
}

AForm::AForm(const AForm &cp) : name(cp.getName()), signature(cp.getSignature()), grade_sig(cp.getGrade_sig()),
	grade_exe(cp.getGrade_exe())
{
	std::cout << "Form copy constructor called" << std::endl;	
}
		
AForm &AForm::operator=(const AForm &member) 
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &member) {
		this->setSignature(member.getSignature());
	}
	return *this;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form is not signed";
}

const std::string AForm::getName(void) const {
	return this->name;
}

bool AForm::getSignature(void) const {
	return this->signature;
}

int AForm::getGrade_sig(void) const {
	return this->grade_sig;
}

int AForm::getGrade_exe(void) const {
	return this->grade_exe;
}

void AForm::setSignature(bool sig) {
	this->signature = sig;
}

void	AForm::beSigned(Bureaucrat &per) {
	if (per.getGrade() <= this->getGrade_sig())
	{
		if (!this->getSignature())
			this->setSignature(true);
		else
			std::cout << "Form already signed!" << std::endl;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat &exec)const {
	(void)exec;
}


std::ostream &operator<<(std::ostream &out, const AForm &member) {
	out << ", is signed: " << member.getSignature()  << ", Grade signature: "
		<< member.getGrade_sig() << ", Grade execution: " << member.getGrade_exe() << std::endl;
	return (out);
}
