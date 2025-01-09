/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap Default constructor called for "
	<< "Default" << std::endl;
	this->max_hp = 100;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called for "
	<< name << std::endl;
	this->max_hp = 100;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

ScavTrap::ScavTrap(const ScavTrap& ScavTrap):ClapTrap(ScavTrap)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap& ScavTrap)
{
	ClapTrap::operator=(ScavTrap);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called for "
	<< this->name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->name << " is Gate guarding"
	<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name
		<< " is dead, of course he cant attack" << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "No energy left, " << this->name
		<< " cant attack" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " is making a move on "
	<< target << ", dealing " << this->attack_damage
	<< " points of damage!" << std::endl;
}













