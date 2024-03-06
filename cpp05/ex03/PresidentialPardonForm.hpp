/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:07:17 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:13:07 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(std::string const target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm &cp);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &mem);

		std::string getTarget(void) const;
		void execute(Bureaucrat &exec) const;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm &mem);
