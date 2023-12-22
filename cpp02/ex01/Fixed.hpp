/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:23 by smallem           #+#    #+#             */
/*   Updated: 2023/10/16 16:05:45 by smallem          ###   ########.fr       */
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
		Fixed &operator=(const Fixed &copy);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
