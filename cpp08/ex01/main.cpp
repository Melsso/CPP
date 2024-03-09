/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:50:07 by smallem           #+#    #+#             */
/*   Updated: 2024/01/19 13:24:18 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main() {
    try {
        // Test constructor with size
        Span spanWithSize(5);
        std::cout << "Span with size 5: ";
        spanWithSize.generateNumbers(); // Generating random numbers
        std::deque<int> sizeList = spanWithSize.getList();
        for (std::deque<int>::const_iterator it = sizeList.begin(); it != sizeList.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
       
        std::cout << "Shortest Span: " << spanWithSize.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spanWithSize.longestSpan() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        // Test copy constructor and assignment operator
        Span copySpan = spanWithSize; // Copy constructor
        std::cout << std::endl;
        std::cout << std::endl;
        Span assignedSpan;
        assignedSpan = spanWithSize; // Assignment operator
        std::cout << std::endl;
        std::cout << std::endl;
        // Test adding numbers manually
        // assignedSpan.addNumber(42); // should fail, span is full
        
        std::cout << "Copy: ";
        std::deque<int> copyList = copySpan.getList();
        for (std::deque<int>::const_iterator it = copyList.begin(); it != copyList.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "Assigned: ";
        std::deque<int> assignedList = assignedSpan.getList();
        for (std::deque<int>::const_iterator it = assignedList.begin(); it != assignedList.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        Span newSpan(10000);
        newSpan.addNumber(105);
        newSpan.addNumber(5);
        newSpan.addNumber(200);
        std::deque<int> l = newSpan.getList();
        std::cout << "newSpan: ";
        for (std::deque<int>::const_iterator it = l.begin(); it != l.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        newSpan.generateNumbers(); // fill the new span with numbers to test shortest and longest span
        std::cout << "newSpan after generating: ";
        std::deque<int> l2 = newSpan.getList();
        for (std::deque<int>::const_iterator it = l2.begin(); it != l2.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << std::endl;
        // Test shortestSpan and longestSpan
        std::cout << "Shortest Span: " << newSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << newSpan.longestSpan() << std::endl;
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
