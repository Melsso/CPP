/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:39:59 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 17:56:07 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"
#include "array.cpp"

int main() {
    try {
        // Test default constructor
        Array<int> intArrayDefault;
        std::cout << "Size of intArrayDefault: " << intArrayDefault.getSize() << std::endl;
        std::cout << std::endl;
        // Test parameterized constructor
        Array<double> doubleArray(5);
        std::cout << "Size of doubleArray: " << doubleArray.getSize() << std::endl;
        std::cout << std::endl;
        
        // Test assignment constructor
        Array<double> doubleArrayCopy;
        doubleArrayCopy = doubleArray;
        std::cout << std::endl;
        
        // Test element access and exception handling
        try {
            doubleArrayCopy[10] = 42.0; // This should throw an InvalidIndex exception
        } catch (const Array<double>::InvalidIndex& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        std::cout << std::endl;
        // Test copy constructor
        Array<double> doubleArrayCopy2(doubleArrayCopy);
        
        std::cout << std::endl;
        // Display sizes
        std::cout << "Size of doubleArrayCopy: " << doubleArrayCopy.getSize() << std::endl;
        std::cout << "Size of doubleArrayCopy2: " << doubleArrayCopy2.getSize() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
