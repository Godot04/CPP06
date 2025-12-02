/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:04:04 by opopov            #+#    #+#             */
/*   Updated: 2025/11/30 15:49:33 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &ser)
{
	(void)ser;
}

Serializer &Serializer::operator=(const Serializer &ser)
{
	(void)ser;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
