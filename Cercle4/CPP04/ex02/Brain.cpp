/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:05:06 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 13:05:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain Constructor called" << std::endl;
	_ideas = new std::string[100];
}

Brain::~Brain()
{
	std::cout << "Brain dead" << std::endl;
	delete[] _ideas;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = brain._ideas[i];
	}
}

Brain &Brain::operator=(const Brain& brain)
{
	std::cout << "Brain = constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = brain._ideas[i];
	}
	return *this;
}
