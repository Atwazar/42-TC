/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:10 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:11 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
	this->name = "Unamned_Zombie";
}

Zombie::Zombie(const Zombie& zombie)
{
	this->name = zombie.name;
}

Zombie &Zombie::operator=(const Zombie& zombie)
{
	this->name = zombie.name;
	return (*this);
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is definitely dead"
	<< std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

void Zombie::change_name(std::string name)
{
	this->name = name;
}
