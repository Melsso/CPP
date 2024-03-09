/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:00:28 by smallem           #+#    #+#             */
/*   Updated: 2024/01/19 13:36:10 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : n(0) {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : n(n) {
	std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Span deconstructor called" << std::endl;
}

Span::Span(const Span &cp) : n(cp.n), list(cp.list) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &member) {
	std::cout << "Span assignment constructor called" << std::endl;
	if (this != &member) {
		this->n = member.n;
		this->list = member.list;
	}
	return *this;
}

void Span::addNumber(int nbr) {
	if (list.size() < this->n)
		list.push_back(nbr);
	else
		throw TooManyNumbers();
}

int Span::shortestSpan(){
	if (list.size() < 2)
		throw NotEnoughNumbers();
	else {
		std::deque<int> l = this->getList();
		int				span;
		int				curr;

		if (l[1] > l[0])
			span = l[1] - l[0];
		else
			span = l[0] - l[1];
		for (size_t i = 1; i < l.size(); i++) {
			if (l[i] > l[i - 1])
				curr = l[i] - l[i - 1];
			else
				curr = l[i - 1] - l[i];
			span = std::min(span, curr);			
		}
		return span;
	}
	return 0;
}

int Span::longestSpan() {
	if (list.size() < 2)
		throw NotEnoughNumbers();
	else {
		std::deque<int>	l = this->getList();
		int				span;
		int				curr;

		if (l[1] > l[0])
			span = l[1] - l[0];
		else
			span = l[0] - l[1];
		for (size_t i = 1; i < l.size(); i++) {
			if (l[i] > l[i - 1])
				curr = l[i] - l[i - 1];
			else
				curr = l[i - 1] - l[i];
			span = std::max(span, curr);
		}
		return span;
	}
	return 0;
}

std::deque<int> Span::getList() const {
	return this->list;
}

void	Span::generateNumbers() {
	std::srand(time(NULL));
	for (unsigned int i = 0; i < this->n; i++) {
		try {
			addNumber(rand() % 100);
		}
		catch (TooManyNumbers &e) {
			return ;
		}
	}
}

const char* Span::TooManyNumbers::what() const throw() {
	return "Too many numbers in container cannot add more!";
}

const char* Span::NotEnoughNumbers::what() const throw() {
	return "Not enogh numbers in container cannot calculate span!";
}

