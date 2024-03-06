/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:40:29 by smallem           #+#    #+#             */
/*   Updated: 2024/03/06 12:30:58 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
	try {
        Bureaucrat bureaucrat("Bob", 2);
        std::cout << bureaucrat;
        std::cout << "Name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat bureaucrat1("Lad", 1);
        bureaucrat1.increment();
        std::cout << bureaucrat1;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try {
        Bureaucrat bureaucrat2("Ash", 150);
        bureaucrat2.decrement();
        std::cout << bureaucrat2;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat bureaucrat1("Lad", 10);
        std::cout << bureaucrat1;
        bureaucrat1.increment();
        std::cout << bureaucrat1;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    try {
        Bureaucrat bureaucrat2("Ash", 140);
        std::cout << bureaucrat2;
        bureaucrat2.decrement();
        std::cout << bureaucrat2;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
