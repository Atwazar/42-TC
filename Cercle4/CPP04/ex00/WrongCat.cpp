/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:36:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal()
{
	std::cout << "birth of a WrongCat" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "death of a WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongAnimal& WrongCat):WrongAnimal(WrongCat)
{
	std::cout << "cloning of a WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongAnimal& WrongCat)
{
	std::cout << "cloning of a WrongCat using '='" << std::endl;
	WrongAnimal::operator=(WrongCat);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
