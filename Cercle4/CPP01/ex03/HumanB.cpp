/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:57 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:58 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	this->name = "Unamned man";
	this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB &HumanB::operator=(const HumanB& humanb)
{
	this->name = humanb.name;
	this->weapon = humanb.weapon;
	return (*this);
}

HumanB::HumanB(const HumanB& humanb)
{
	this->name = humanb.name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::string weapon;

	if (this->weapon == NULL)
		weapon = "bare hands";
	else
		weapon = (this->weapon)->getType();
	std::cout << this->name << " attacks with their "
			<< weapon << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}
