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
	_brain = new Brain;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "death of a Cat" << std::endl;
	delete(_brain);
}

Cat::Cat(const Cat& Cat):Animal(Cat)
{
	std::cout << "cloning of a Cat" << std::endl;
	_brain = new Brain;
	*_brain = *Cat._brain;
}

Cat &Cat::operator=(const Cat& Cat)
{
	std::cout << "cloning of a Cat using '='" << std::endl;
	Animal::operator=(Cat);
	*_brain = *Cat._brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
