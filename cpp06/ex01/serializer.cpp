/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:51:09 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 12:25:46 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

Serializer::Serializer(void) {
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &cp) {
	std::cout << "Serializer copy constructor called" << std::endl;	
	*this = cp;
}

Serializer::~Serializer(void) {
	std::cout << "Serializer deconstructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &member)
{
    std::cout << "Serializer assignation operator called" << std::endl;
    if (this != &member)
        (void)member;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
