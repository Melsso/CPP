/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:13:28 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 17:49:47 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

template<typename T>
Array<T>::Array() : arr(nullptr), size(0) {
	std::cout << "Array default constructor called" << std::endl;
	
}

template<typename T>
Array<T>::Array(unsigned int n) : size(n) {
	std::cout << "Array constructor called" << std::endl;
	this->arr = new T[this->size]();
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &member) {
	std::cout << "Array assignment constructor called" << std::endl;
	if (this != &member)
	{
		delete [] this->arr;
		this->size = member.size;
		this->arr = new T[this->size];
		for (unsigned int i = 0; i < this->size; i++)
			this->arr[i] = member.arr[i];
	}
	return *this;
}

template<typename T>
const char* Array<T>::InvalidIndex::what() const throw() {
	return "Index out of bounds";
}

template<typename T>
T &Array<T>::operator[](unsigned int ind) {
	if (this->size <= ind)
		throw InvalidIndex();
	else
		return this->arr[ind];
}

template<typename T>
Array<T>::Array(const Array<T> &cp) : size(cp.size) {
	std::cout << "Array copy constructor called" << std::endl;
	this->arr = new T[size];
	for (unsigned int i = 0; i < this->size; i++)
		this->arr[i] = cp.arr[i];
}

template<typename T>
Array<T>::~Array() {
	std::cout << "Array deconstructor called" << std::endl;
	delete [] this->arr;
}

template<typename T>
unsigned int Array<T>::getSize() const {
	return this->size;
}
