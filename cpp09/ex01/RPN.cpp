/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:00:16 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:39:17 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) : input(input) {
	try {
		check_input();
	}
	catch (InvalidInput &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
	try {
		compute();
	}
	catch(DivisionByZero& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

RPN::~RPN() {
	
}

RPN::RPN(const RPN &cp) : input(cp.input), numbers(cp.numbers) {

}

RPN &RPN::operator=(const RPN &member) {
	if (this != &member) {
		this->numbers = member.numbers;
		this->input = member.input;
	}
	return *this;
} 

void RPN::check_input(void) {
	char c;

	for (unsigned int i = 0; i < this->input.length(); i++) {
		c = this->input[i];
		if (!isnumber(c) && c != '+' && c != '-' && c != '/'
			&& c != '*' && c != ' ')
			throw InvalidInput();
	}
}

void RPN::compute(void) {
	double	val1, val2;
	char	op;

	for (unsigned int i = 0; i < this->input.length(); i++) {
		op = this->input[i];
		if (isnumber(op))
			this->numbers.push((double)(op - '0'));
		else if (op == '+' || op == '-' || op == '*' || op == '/') {
			val1 = this->numbers.top();
			this->numbers.pop();
			val2 = this->numbers.top();
			this->numbers.pop();
			if (op == '/' && val1 == 0.0)
				throw DivisionByZero();
			switch (op) {
				case '+':
				val1 = val1 + val2;
				break ;
				case '-':
					val1 = val2 - val1;
					break ;
				case '*':
					val1 = val1 * val2;
					break ;
				case '/':
					val1 = val2 / val1;
					break ;
			}
			this->numbers.push(val1);
		}
	}
	std::cout << "Result is: " << this->numbers.top() << std::endl;
}

const char* RPN::InvalidInput::what() const throw() {
	return "Invalid input!";
}

const char* RPN::DivisionByZero::what() const throw() {
	return "Invalid operation: Division by zero!";
}
