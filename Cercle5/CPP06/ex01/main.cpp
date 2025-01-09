/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:23 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 17:34:24 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void print_data(Data data)
{
	std::cout << "int_value =" << data.int_value << std::endl;
	std::cout << "string_value =" << data.string_value << std::endl;
	std::cout << "char_value =" << data.char_value << std::endl;
}

int main ()
{
	Data data_test;

	data_test.int_value = 123456789;
	data_test.string_value = "salut ca va";
	data_test.char_value = '=';

	print_data(data_test);
	uintptr_t test = Serializer::serialize(&data_test);
	std::cout << "data serialized is "<< test << std::endl;
	Data transformed = *(Serializer::deserialize(test));

	print_data(transformed);
}

