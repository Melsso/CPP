/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:35:27 by smallem           #+#    #+#             */
/*   Updated: 2023/12/12 14:43:46 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	
	if (argc == 4)
	{
		std::string in = std::string(argv[1]);
		std::ifstream inputFile(in);
		std::string s1 = std::string(argv[2]);
		std::string s2 = std::string(argv[3]);
		std::string line;

		if (!inputFile)
		{
			std::cout << "Failed to open the file: " << in << std::endl;
			return (1);
		}
		std::ofstream outputFile(in + ".replace");
		if (!outputFile)
		{
			inputFile.close();
			std::cout << "Failed to open the file: " << in + ".replace" << std::endl;
			return (1);
		}
		
		while (std::getline(inputFile, line)) {
			if (!s1.empty())
			{
				size_t pos;
				size_t start = 0;
				while ((pos = line.find(s1, start)) != std::string::npos ) {
					outputFile << line.substr(start, pos - start) << s2;
					start = pos + s1.length();
				}
				outputFile << line.substr(start) << std::endl;
			}
			else
				outputFile << line << std::endl;
		}	
		inputFile.close();
		outputFile.close();
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " Filename s1 s2" << std::endl;
		return (0);
	}
	return (0);
}
