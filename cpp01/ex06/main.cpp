/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:05 by smallem           #+#    #+#             */
/*   Updated: 2023/10/13 16:44:54 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl complaint;

	if (argc == 2)
	{
		complaint.complain("DEBUG", std::string(argv[1]));
		complaint.complain("INFO", std::string(argv[1]));
		complaint.complain("WARNING", std::string(argv[1]));
		complaint.complain("ERROR", std::string(argv[1]));
	}
	else
		std::cout << "Usage: " << argv[0] << " Filter_level" << std::endl;
	return (0);
}
