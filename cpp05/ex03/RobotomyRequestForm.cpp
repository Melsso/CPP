/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:21:59 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:52:21 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", false, 72, 45), target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request Form", false, 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cp) : AForm(cp), target(cp.getTarget()) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &mem) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &mem)
	{
		this->setSignature(mem.getSignature());
		this->target = mem.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const {
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat &exec) const {
	if (this->getSignature() && exec.getGrade() <= this->getGrade_exe())
	{
		std::cout << "Some drilling noise..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << ": robotomy has failed" << std::endl;
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

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm &mem) {
    out << "Name: " << mem.getName() << ", Target: " << mem.getTarget();
	out << static_cast<const AForm&>(mem);
	return out;
}
