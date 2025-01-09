/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap Default constructor called for "
	<< "Default" << std::endl;
	this->max_hp = 100;
	this->hit_points = 100;
	this->attack_damage = 20;
	this->energy_points = 50;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called for "
	<< name << std::endl;
	this->hit_points = 100;
	this->attack_damage = 100;
	this->energy_points = 30;
	this->max_hp = 100;
}

FragTrap::FragTrap(const FragTrap& FragTrap):ClapTrap(FragTrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap& FragTrap)
{
	ClapTrap::operator=(FragTrap);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called for "
	<< this->name << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << this->name << " is asking for some highfives"
	<< std::endl;
}

void FragTrap::attack(const std::string& target)
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
	std::cout << "FragTrap " << this->name << " is making a move on "
	<< target << ", dealing " << this->attack_damage
	<< " points of damage!" << std::endl;
}












