/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:29:23 by smallem           #+#    #+#             */
/*   Updated: 2023/12/15 18:46:13 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->fixed_point = 0;
}

Fixed::Fixed(const int nbr) {
	this->setRawBits(nbr << this->frac_bits);
}

Fixed::Fixed(const float fpnbr) {
	this->setRawBits(fpnbr * (1 << this->frac_bits));
}

Fixed::~Fixed(void) {
	
}

Fixed::Fixed(const Fixed &copy) {
	this->setRawBits(copy.getRawBits());
}


Fixed &Fixed::operator=(const Fixed &nbr) {
	if (this != &nbr) {
		this->setRawBits(nbr.getRawBits());
	}
	return *this;
}

////////////////////OPERATOR OVERLOAD///////////////////

bool Fixed::operator>(const Fixed &nbr) const {
	if (this->toFloat() > nbr.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &nbr) const {
	if (this->toFloat() >= nbr.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &nbr) const {
	if (this->toFloat() < nbr.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &nbr) const {
	if (this->toFloat() <= nbr.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &nbr) const {
	if (this->toFloat() == nbr.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &nbr) const {
	if (this->toFloat() != nbr.toFloat())
		return true;
	else
		return false;
}

float Fixed::operator+(const Fixed &nbr) const {
	return (this->toFloat() + nbr.toFloat());
}

float Fixed::operator-(const Fixed &nbr) const {
	return (this->toFloat() - nbr.toFloat());
}

float Fixed::operator*(const Fixed &nbr) const {
	return (this->toFloat() * nbr.toFloat());
}

float Fixed::operator/(const Fixed &nbr) const {
	return (this->toFloat() / nbr.toFloat());
}

Fixed Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}
////////////////////MEMBER FUNCTIONS///////////////////

int Fixed::getRawBits(void) const {
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(this->getRawBits()) / ((float)(1 << this->frac_bits)));
}

int Fixed::toInt(void) const {
	return (this->getRawBits() >> this->frac_bits);
}

const Fixed &Fixed::min(const Fixed &nbr1, const Fixed &nbr2) {
	if (nbr1.getRawBits() > nbr2.getRawBits())	
		return (nbr2);
	else
		return (nbr1);
}

Fixed &Fixed::min(Fixed &nbr1, Fixed &nbr2) {
	if (nbr1.getRawBits() > nbr2.getRawBits())	
		return (nbr2);
	else
		return (nbr1);
}

const Fixed &Fixed::max(const Fixed &nbr1, const Fixed &nbr2) {
	if (nbr1.getRawBits() > nbr2.getRawBits())	
		return (nbr1);
	else
		return (nbr2);
}

Fixed &Fixed::max(Fixed &nbr1, Fixed &nbr2) {
	if (nbr1.getRawBits() > nbr2.getRawBits())	
		return (nbr1);
	else
		return (nbr2);
}

////////////////////OTHER FUNCTIONS///////////////////

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}
