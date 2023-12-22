/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:05 by smallem           #+#    #+#             */
/*   Updated: 2023/12/12 14:54:35 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl complaint;

	complaint.complain("DEBUG");
	complaint.complain("INFO");
	complaint.complain("WARNING");
	complaint.complain("ERROR");
	return (0);
}
