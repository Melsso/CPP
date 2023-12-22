/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:29:23 by smallem           #+#    #+#             */
/*   Updated: 2023/12/19 15:47:52 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}


Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &copy) : fixed_point(copy.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy) {
		this->fixed_point = copy.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}
