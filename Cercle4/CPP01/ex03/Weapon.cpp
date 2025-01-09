/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:26 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:27 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "Undefined weapon";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon &Weapon::operator=(const Weapon& weapon)
{
	this->type = weapon.type;
	return (*this);
}

Weapon::Weapon(const Weapon& weapon)
{
	this->type = weapon.type;
}

Weapon::~Weapon()
{
}

std::string& Weapon::getType()
{
	std::string& type_ref = this->type;
	return (type_ref);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
