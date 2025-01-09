/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:31 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:33 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "birth of an animal" << std::endl;
	_type = "Animal";
}

Animal::~Animal()
{
	std::cout << "death of an animal" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "cloning of an animal" << std::endl;
	_type = animal._type;
}

Animal &Animal::operator=(const Animal& animal)
{
	std::cout << "cloning of an animal using '='" << std::endl;
	_type = animal._type;
	return *this;
}
