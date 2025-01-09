/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:36:03 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:36:05 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal()
{
	std::cout << "birth of a Dog" << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "death of a Dog" << std::endl;
}

Dog::Dog(const Animal& Dog):Animal(Dog)
{
	std::cout << "cloning of a Dog" << std::endl;
}

Dog &Dog::operator=(const Animal& Dog)
{
	std::cout << "cloning of a Dog using '='" << std::endl;
	Animal::operator=(Dog);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
