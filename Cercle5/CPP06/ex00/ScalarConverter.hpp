/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:29 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 17:34:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <cmath>

#define WEIRD 0
#define DOUBLE 1
#define FLOAT 2
#define INT 3
#define CHAR 4
#define PRINTABLE 5

#define MAY 0
#define MAY_NOT 1

class ScalarConverter
{
	public :

		static void print(const char *data, int type);
		static void convert(std::string);

	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter& other);
};
