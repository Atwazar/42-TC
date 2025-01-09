/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():max_hp(10)
{
	std::cout << "Default constructor called for Claptrap" << std::endl;
	this->name = "Default";
	this->hit_points = 10;
	this->attack_damage = 0;
	this->energy_points = 10;
}

ClapTrap::ClapTrap(std::string name):max_hp(10)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->attack_damage = 0;
	this->energy_points = 10;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap):max_hp(10)
{
	std::cout << "ClapTrap Copy constructor called for " << name << std::endl;
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->attack_damage = claptrap.attack_damage;
	this->energy_points = claptrap.energy_points;
	this->max_hp = claptrap.max_hp;
}
ClapTrap &ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "ClapTrap Copy assignment operator called for " << name << std::endl;
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->attack_damage = claptrap.attack_damage;
	this->energy_points = claptrap.energy_points;
	this->max_hp = claptrap.max_hp;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << this->name << " attacks "
	<< target << ", causing " << this->attack_damage
	<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0 || this->energy_points == 0)
	{
		std::cout << "the dude was already dead, nice waste of energy points"
		<< std::endl;
		return ;
	}
	if (this->hit_points < amount)
		amount = hit_points;
	this->hit_points -= amount;
	std::cout << this->name << " has suffered " << amount
	<< " points of damage" << std::endl;
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " has died"<< std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name
		<< " is dead, its too late for him to repair himself"
		<< std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << "No energy left, " << this->name
		<< " cant repair" << std::endl;
		return ;
	}
	this->energy_points--;
	if (this->hit_points + amount > this->max_hp)
		amount = this->max_hp - this->hit_points;
	this->hit_points += amount;
	std::cout << this->name << " has repaired himself for " << amount
	<< " hit points";
	if (amount == 0)
		std::cout << ", he just wasted 1 energy points";
	std::cout << std::endl;
}

void ClapTrap::set_attack(unsigned int new_attack)
{
	this->attack_damage = new_attack;
}

unsigned int ClapTrap::get_attack()
{
	return (this->attack_damage);
}

void ClapTrap::present_yourself(void)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "dead people dont talk" << std::endl;
		return ;
	}
	std::cout << "\nMy name is " << this->name <<
	", I have " << this->hit_points << " hit points,"
	<< this->energy_points
	<< " energy points and my attack damage is "
	<< this->attack_damage
	<< std::endl;
}











