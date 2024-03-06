/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:22:30 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:13:15 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
		RobotomyRequestForm(void);
	
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm &cp);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &mem);

		std::string getTarget(void) const;
		void execute(Bureaucrat &exec) const;
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm &mem);
