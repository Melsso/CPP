/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:49:43 by smallem           #+#    #+#             */
/*   Updated: 2024/01/18 15:37:01 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <exception>

class ValueNotFound : public std::exception {
	public:
		virtual const char* what() const throw();
};

const char* ValueNotFound::what() const throw() {
	return "Value not found in container";
}

template<typename T>
void easyfind(T &list, int x) {
	typename T::iterator it = std::find(list.begin(), list.end(), x);

	if (it != list.end()) {
        std::cout << "Found the value: " << *it << std::endl;
    }
	else
        throw ValueNotFound();
}

#endif
