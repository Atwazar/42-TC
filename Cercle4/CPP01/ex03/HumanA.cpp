/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:03:02 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:03:03 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	this->name = "Unamned man";
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA &HumanA::operator=(const HumanA& humana)
{
	this->name = humana.name;
	this->weapon = humana.weapon;
	return (*this);
}

HumanA::HumanA(const HumanA& humana)
{
	this->name = humana.name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their "
			<< this->weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}
