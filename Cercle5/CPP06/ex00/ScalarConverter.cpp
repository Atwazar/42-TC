/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:13 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 17:34:14 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

void ScalarConverter::print(const char *data, int type)
{
	std::cout << "char: ";
	double double_value = strtod(data, NULL);
	if (type == PRINTABLE)
		std::cout << static_cast<char>(double_value)<< std::endl;
	else if (type == CHAR)
		std::cout << "not displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (type >= INT)
		std::cout << static_cast<int>(double_value) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (type >= FLOAT)
		std::cout << static_cast<float>(double_value) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (type >= DOUBLE)
		std::cout << double_value << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	const char *data = input.c_str();
	int length = input.length();
	double double_value;
	double double_int_value;
	int has_dot = 0;

	if (input == "+inff" || input == "-inff" || input == "nanf")
		return (print(data, FLOAT));
	if (input == "+inf" || input == "-inf" || input == "nan")
		return (print(data, DOUBLE));

	if (!isdigit(data[0]))
	{
		if (data[0] == '-' || data[0] == '+')
		{
			if (length == 1)
				return (print(data, WEIRD));
		}
		else
		{
			if (data[0] == '.')
				has_dot++;
			else
				return (print(data, WEIRD));
		}
	}
	for (int i = 1; i < length; i++)
	{
		if (i == length - 1)
		{
			if (!isdigit(data[i]) && data[i] != 'f')
				return (print(data, WEIRD));
		}
		else if (data[i] == '.')
		{
			if (has_dot++ == 1)
				return (print(data, WEIRD));
		}
		else if (!isdigit(data[i]))
			return (print(data, WEIRD));
	}
	double_value = strtod(data, NULL);
	if (double_value == 0)
		return (print(data, CHAR));
	if (double_value > __FLT_MAX__ || double_value < -__FLT_MAX__)
		return (print(data, DOUBLE));
	double_int_value = floor(double_value);
	if (double_value - double_int_value || double_int_value > INT_MAX || double_int_value < INT_MIN)
		return (print(data, FLOAT));
	int int_val = double_int_value;
	if (!isascii(int_val))
		return (print(data, INT));
	if (!isprint(int_val))
		return (print(data, CHAR));
	return (print(data, PRINTABLE));
}
