/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:03:18 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:03:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon fork = Weapon("fork");
	Weapon knife = Weapon("knife");
	Weapon spoon = Weapon("spoon");
	HumanA Jeanjean("Jeanjean", fork);
	Jeanjean.attack();
	Jeanjean.setWeapon(knife);
	Jeanjean.attack();
	HumanB Peacefull_guy("Peacefull_guy");
	Peacefull_guy.attack();
	Peacefull_guy.setWeapon(spoon);
	Peacefull_guy.attack();
	spoon.setType("Bigger spoon");
	Peacefull_guy.attack();
}
