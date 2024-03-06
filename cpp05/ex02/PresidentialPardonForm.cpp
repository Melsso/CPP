/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:59:14 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:52:25 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", false, 25, 5), target("default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon Form", false, 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cp) : AForm(cp), target(cp.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &mem) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &mem)
	{
		this->setSignature(mem.getSignature());
		this->target = mem.getTarget();
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const {
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat &exec) const {
	if (this->getSignature() && exec.getGrade() <= this->getGrade_exe())
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		std::cout << exec.getName() << " executed " << this->getName() << std::endl;
	}
	else
	{
		if (!this->getSignature())
			throw AForm::FormNotSigned();
		else
			throw AForm::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &mem) {
    out << "Name: " << mem.getName() << ", Target: " << mem.getTarget();
	out << static_cast<const AForm&>(mem);
	return out;
}
