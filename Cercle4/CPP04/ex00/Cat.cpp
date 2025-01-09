/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:49 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal()
{
	std::cout << "birth of a Cat" << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "death of a Cat" << std::endl;
}

Cat::Cat(const Animal& Cat):Animal(Cat)
{
	std::cout << "cloning of a Cat" << std::endl;
}

Cat &Cat::operator=(const Animal& Cat)
{
	std::cout << "cloning of a Cat using '='" << std::endl;
	Animal::operator=(Cat);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
