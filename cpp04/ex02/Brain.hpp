/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:57:33 by smallem           #+#    #+#             */
/*   Updated: 2023/10/19 10:29:15 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain &cp);
		void setIdea(int ind, std::string idea);
		std::string getIdea(int ind);
		Brain &operator=(Brain &member);
};

#endif
