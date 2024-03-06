/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:09:27 by smallem           #+#    #+#             */
/*   Updated: 2023/12/13 16:01:34 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &member);

#endif
