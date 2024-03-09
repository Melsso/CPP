/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:50:12 by smallem           #+#    #+#             */
/*   Updated: 2024/01/19 16:04:45 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include "mutantstack.cpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Element at top of stack is: " << mstack.top() << std::endl;
	std::cout << std::endl;
	mstack.pop();
	
	std::cout << "Stack size is: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	it++;
	it--;
	std::cout << "Stack values: ";
	while (it != ite) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
