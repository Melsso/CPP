/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:29:23 by smallem           #+#    #+#             */
/*   Updated: 2023/12/19 17:23:33 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(nbr << this->frac_bits);
}

Fixed::Fixed(const float fpnbr) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(fpnbr * (float)(1 << this->frac_bits));
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
		this->setRawBits(copy.getRawBits());
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(this->getRawBits()) / (float)(1 << frac_bits));
}

int Fixed::toInt(void) const {
	return (this->getRawBits() >> frac_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}
