/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:09:27 by smallem           #+#    #+#             */
/*   Updated: 2023/12/13 18:21:26 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		class GradeTooLow : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHigh : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		Bureaucrat(const std::string &Name, int grade);
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &cp);
		
		Bureaucrat &operator=(const Bureaucrat &member);
		void setGrade(int grade);
		int getGrade(void) const;
		const std::string getName(void) const;
		void increment(void);
		void decrement(void);
		void signForm(AForm &form);
		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &member);
