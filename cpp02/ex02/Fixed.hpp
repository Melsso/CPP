/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:23 by smallem           #+#    #+#             */
/*   Updated: 2023/12/15 18:45:29 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float fpnbr);
		Fixed(const Fixed &copy);
		~Fixed(void);
		Fixed &operator=(const Fixed &nbr);
		
		
		bool operator>(const Fixed &nbr) const;
		bool operator<(const Fixed &nbr) const;
		bool operator>=(const Fixed &nbr) const;
		bool operator<=(const Fixed &nbr) const;
		bool operator==(const Fixed &nbr) const;
		bool operator!=(const Fixed &nbr) const;
		
		float operator+(const Fixed &nbr) const;
		float operator-(const Fixed &nbr) const;
		float operator*(const Fixed &nbr) const;
		float operator/(const Fixed &nbr) const;
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		
		static const Fixed &min(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed &min(Fixed &nbr1, Fixed &nbr2);
		static const Fixed &max(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed &max(Fixed &nbr1, Fixed &nbr2);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
