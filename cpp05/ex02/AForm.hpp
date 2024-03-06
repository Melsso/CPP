/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:48 by smallem           #+#    #+#             */
/*   Updated: 2024/02/21 12:14:45 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string name;
		bool	signature;
		const int	grade_sig;
		const int	grade_exe;
		AForm(void);
		AForm(const std::string &Name, bool sig, int g_s, int g_e);
	
	public:
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		virtual ~AForm(void);
		AForm(const AForm &cp);
		AForm &operator=(const AForm &member);

		void	setSignature(bool sig);
		bool	getSignature(void) const;
		const std::string getName(void) const;
		int getGrade_sig(void) const;
		int getGrade_exe(void) const;

		void	beSigned(Bureaucrat &per);
		virtual void execute(Bureaucrat &exec)const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &member);
