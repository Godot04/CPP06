/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:03:53 by opopov            #+#    #+#             */
/*   Updated: 2025/12/01 11:02:04 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data *data = new Data;
	data->name = "Bob";
	data->age = 42;
	data->job = "Lawyer";

	// Before serialization
	std::cout << "-----------------------" << std::endl;
	std::cout << "Before serialization" << std::endl;
	std::cout << data->name << std::endl;
	std::cout << data->age << std::endl;
	std::cout << data->job << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "-----------------------" << std::endl;
	std::cout << "Data after serialization" << std::endl;
	std::cout << "Memory address: " << &data << std::endl;
	std::cout << "Raw memory address: " << raw << std::endl;
	Data *serialized = Serializer::deserialize(raw);

	// After deserialization
	std::cout << "-----------------------" << std::endl;
	std::cout << "After deserialization" << std::endl;
	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;
	std::cout << serialized->job << std::endl;

	delete data;
	return (0);
}
