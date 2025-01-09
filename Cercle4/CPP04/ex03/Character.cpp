/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:15:47 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:48 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Character.hpp"


Character::Character(std::string name)
{
	_name = name;
	for (int i=0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character()
{
	_name = "Unamned";
	for (int i=0; i < 4; i++)
		_inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != 0)
			delete (_inventory[i]);
	}
}

Character::Character(const Character& Character):_name(Character._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (Character._inventory[i])
			_inventory[i] = Character._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character& Character)
{
	_name = Character._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != 0)
			delete (_inventory[i]);
		_inventory[i] = 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (Character._inventory[i])
			_inventory[i] = Character._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == 0)
		return;
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == 0)
		return;
	_inventory[idx]->use(target);
}

AMateria* Character::access_inventory(int idx)
{
	if (idx < 0 || idx > 3)
		return (0);
	return (_inventory[idx]);
}

