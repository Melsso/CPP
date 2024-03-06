/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:58:27 by smallem           #+#    #+#             */
/*   Updated: 2023/12/13 16:23:48 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default"), signature(false), grade_sig(150), grade_exe(150)
{
	std::cout << "Form default constructor called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exe() < 1)
		throw GradeTooHighException();
	else if (this->getGrade_sig() > 150 || this->getGrade_exe() > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string &Name, bool sig, int g_s, int g_e) : name(Name), signature(sig),
	grade_sig(g_s), grade_exe(g_e)
{
	std::cout << "Form constructor called" << std::endl;
	if (this->getGrade_sig() < 1 || this->getGrade_exe() < 1)
		throw GradeTooHighException();
	else if (this->getGrade_sig() > 150 || this->getGrade_exe() > 150)
		throw GradeTooLowException();
}

Form::~Form(void) 
{
	std::cout << "Form: " << this->getName() << " deconstructor called" << std::endl;
}

Form::Form(const Form &cp) : name(cp.getName()), signature(cp.getSignature()), grade_sig(cp.getGrade_sig()),
	grade_exe(cp.getGrade_exe())
{
	std::cout << "Form copy constructor called" << std::endl;	
}
		
Form &Form::operator=(const Form &member) 
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &member) {
		this->setSignature(member.getSignature());
	}
	return *this;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const std::string Form::getName(void) const {
	return this->name;
}

bool Form::getSignature(void) const {
	return this->signature;
}

int Form::getGrade_sig(void) const {
	return this->grade_sig;
}

int Form::getGrade_exe(void) const {
	return this->grade_exe;
}

void Form::setSignature(bool sig) {
	this->signature = sig;
}

void	Form::beSigned(Bureaucrat &per) {
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

std::ostream &operator<<(std::ostream &out, const Form &member) {
	out << member.getName() << ", is signed: " << member.getSignature()  << ", Grade signature: "
		<< member.getGrade_sig() << ", Grade execution: " << member.getGrade_exe() << std::endl;
	return (out);
}
