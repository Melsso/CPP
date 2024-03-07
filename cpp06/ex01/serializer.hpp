/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:51:07 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 12:24:09 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data {
	std::string str;
	int			nbr;
	Data		*next;
}	Data;

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer &cp);
		~Serializer(void);
		Serializer &operator=(const Serializer &member);
	
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
