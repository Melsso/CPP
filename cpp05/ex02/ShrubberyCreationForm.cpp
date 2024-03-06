/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:28:18 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:52:16 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", false, 145, 137), target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation Form", false, 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cp) : AForm(cp), target(cp.getTarget()) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &mem) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &mem)
	{
		this->setSignature(mem.getSignature());
		this->target = mem.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat &exec) const {
	if (this->getSignature() && exec.getGrade() <= this->getGrade_exe())
	{
		std::ofstream outfile ("shrubbery");
		if (outfile.is_open())
		{
			outfile << "     ccee88oo" << std::endl;
            outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
            outfile << " dOB69QO8PdUOpugoO9bD" << std::endl;
            outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
            outfile << "    6OcODOU Odcbq8p" << std::endl;
            outfile << "       8c0c0dd" << std::endl;
            outfile.close();
		}
		else
			std::cerr << "Unable to open file: " << "shrubbery" << std::endl;
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

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm &mem) {
    out << "Name: " << mem.getName() << ", Target: " << mem.getTarget();
	out << static_cast<const AForm&>(mem);
	return out;
}
