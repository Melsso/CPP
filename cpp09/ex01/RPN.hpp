/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:36:55 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:38:15 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <exception>

class RPN {
	private:
		std::string input;
		std::stack<double> numbers;
	public:
		RPN(std::string input);
		~RPN();
		RPN(const RPN &cp);
		RPN &operator=(const RPN &member);

		void check_input(void);
		void compute(void);
		
		class InvalidInput : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class DivisionByZero : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
