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

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "the program only works with one argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (1);
}

