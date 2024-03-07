/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:54:59 by smallem           #+#    #+#             */
/*   Updated: 2024/03/06 17:46:51 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main(void) {
	Data 		my_data;
	uintptr_t	serialized_value;
	Data		*deserialized_data;

	my_data.str = "hello";
	my_data.nbr = 42;
	my_data.next = NULL;

	serialized_value = Serializer::serialize(&my_data);
	deserialized_data = Serializer::deserialize(serialized_value);

	if (deserialized_data == &my_data) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "Initial data: " << my_data.str << " " << my_data.nbr << " ptr: " << &my_data<< std::endl;
		std::cout << "Deserialized data: " << deserialized_data->str << " " << deserialized_data->nbr << " ptr: " << deserialized_data << std::endl;
	}
	else
		std::cout << "Serialization and deserialization unsuccessful!" << std::endl;
}
