/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:12:20 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 17:50:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>

class Array {
	private:
		T				*arr;
		unsigned int	size;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array<T> &cp);
		Array<T> &operator=(const Array<T> &member);
		T &operator[](unsigned int ind);
		unsigned int getSize(void) const;

		class InvalidIndex : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
