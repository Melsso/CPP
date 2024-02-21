/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:57:35 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 10:11:39 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain::Brain(Brain &cp) {
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &cp)
		*this = cp;
}

void Brain::setIdea(int ind, std::string idea) {
	if (ind < 100 && ind >= 0)
		this->ideas[ind] = idea;
	else
		std::cout << "Invalid index!" << std::endl;
}

std::string Brain::getIdea(int ind) {
	if (ind < 100 && ind >= 0)
		return this->ideas[ind];
	else
	{
		std::cout << "Invalid index!" << std::endl;
		return (NULL);
	}
}

Brain &Brain::operator=(Brain &member) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &member)
	{
		for (int i = 0; i < 100; i++)
			this->setIdea(i, member.getIdea(i));
	}
	return *this;
}
