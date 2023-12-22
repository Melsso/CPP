/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:33:10 by smallem           #+#    #+#             */
/*   Updated: 2023/12/15 18:21:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	std::cout << "this is A: " << a << std::endl;
	std::cout << "this is ++A: " << ++a << std::endl;
	std::cout << "this is A: " << a << std::endl;
	std::cout << "this is A++: " << a++ << std::endl;
	std::cout << "this is A: " << a << std::endl;
	std::cout << "this is --A: " << --a << std::endl;
	std::cout << "this is A: " << a << std::endl;
	std::cout << "this is A--: " << a-- << std::endl;
	std::cout << "this is A: " << a << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c = b;
	std::cout << "this is B: " << b << std::endl;
	std::cout << "this is C: " << c << std::endl;

	a = 2;
	std::cout << "this is A " << a << std::endl;
	std::cout << "this is Max(A,B): " << Fixed::max( a, b ) << std::endl;
	std::cout << "this is Min(A,B) " << Fixed::min( a, b) << std::endl;
	std::cout << "this is A + B: " << (a + b) << std::endl;
	std::cout << "this is A - B: " << (a - b) << std::endl;
	std::cout << "this is A * B: " << (a * b) << std::endl;
	std::cout << "this is A / B: " << (a / b) << std::endl;
	std::cout << "this is A > B: " << (a > b) << std::endl;
	std::cout << "this is A < B: " << (a < b) << std::endl;
	std::cout << "this is A >= B: " << (a >= b) << std::endl;
	std::cout << "this is A <= B: " << (a <= b) << std::endl;
	std::cout << "this is A == B: " << (a == b) << std::endl;
	return 0;
}
