/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:48 by smallem           #+#    #+#             */
/*   Updated: 2023/12/13 15:48:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool	signature;
		const int	grade_sig;
		const int	grade_exe;
	public:
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		Form(void);
		Form(const std::string &Name, bool sig, int g_s, int g_e);
		Form(const Form &cp);
		~Form(void);
		Form &operator=(const Form &member);

		void	setSignature(bool sig);
		bool	getSignature(void) const;
		const std::string getName(void) const;
		int getGrade_sig(void) const;
		int getGrade_exe(void) const;

		void	beSigned(Bureaucrat &per);
};

std::ostream &operator<<(std::ostream &out, const Form &member);

#endif
