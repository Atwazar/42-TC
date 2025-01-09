/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:00:56 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/23 15:00:57 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	// uintptr_t serialized = reinterpret_cast<uintptr_t>(ptr);
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	// Data *deserialized = reinterpret_cast<Data *>(raw);
	return (reinterpret_cast<Data *>(raw));
}

