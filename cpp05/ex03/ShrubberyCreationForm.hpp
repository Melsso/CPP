/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:27:50 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:13:21 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
		ShrubberyCreationForm(void);
	
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm &cp);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &mem);

		std::string getTarget(void) const;
		void execute(Bureaucrat &exec) const;
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm &mem);
