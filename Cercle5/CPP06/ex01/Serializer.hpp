/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:00:51 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/23 15:00:52 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private :
		~Serializer();
		Serializer();
		Serializer(const Serializer& other);
		Serializer &operator=(const Serializer& other);
};
