/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:22 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:23 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default")
{
	std::cout << "DiamondTrap Default constructor called for "
	<< name << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	this->max_hp = FragTrap::max_hp;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"),
ScavTrap(name), FragTrap(name),	name(name)
{
	std::cout << "DiamondTrap Default constructor called for "
	<< name << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	this->max_hp = FragTrap::max_hp;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->ClapTrap::name = other.ClapTrap::name;
	this->ScavTrap::name = other.ScavTrap::name;
	this->FragTrap::name = other.FragTrap::name;
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called for "
	<< this->name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "Hello, my name is " << this->ClapTrap::name << ", "
	<< this->name << " " << this->ClapTrap::name << std::endl;
}












