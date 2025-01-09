/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:05:06 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 13:05:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	ICharacter* you =  new Character("you");
	ICharacter* me = new Character("me");
	std::cout << "test cloning" << std::endl;
	AMateria *ice_clone = ice->clone();
	ice_clone->use(*you);
	std::cout << "test equiping" << std::endl;
	ice->use(*you);
	you->equip(ice);
	you->equip(cure);
	you->use(0, *me);
	you->use(1, *me);
	you->equip(ice);
	you->use(2, *me);
	std::cout << "test copying" << std::endl;
	me->equip(ice_clone);
	me->use(0, *me);
	*me = *you;
	me->use(1, *me);
	std::cout << "test unequip" << std::endl;
	AMateria *save = you->access_inventory(1);
	you->use(1, *me);
	you->unequip(1);
	you->use(1, *me);
	std::cout << "test source learn" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	AMateria* tmp_ice;
	tmp_ice = src->createMateria("ice");
	tmp_ice->use(*you);
	AMateria* tmp_non_existing;
	tmp_non_existing = src->createMateria("cure");
	if (!tmp_non_existing)
		std::cout << "couldnt create from nothing" << std::endl;
	delete you;
	delete save;
	delete me;
	delete tmp_ice;
	delete src;
	return (0);

// 	MateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
}
