/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:39 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:36:40 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "birth of an WrongAnimal" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "death of an WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
{
	_type = WrongAnimal._type;
	std::cout << "cloning of an WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& WrongAnimal)
{
	_type = WrongAnimal._type;
	std::cout << "cloning of an WrongAnimal using '='" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Random WrongAnimal Noises*"
		<< std::endl;
}
