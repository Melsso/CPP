/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:38:45 by smallem           #+#    #+#             */
/*   Updated: 2024/01/19 15:47:55 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	std::cout << "MutantStack constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
	std::stack<T>::operator=(src);
	std::cout << "MutantStack assignment constructor called" << std::endl;
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack deconstructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return this->c.end();
}
