/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:23 by smallem           #+#    #+#             */
/*   Updated: 2023/10/16 14:49:54 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
	private:
		int fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
