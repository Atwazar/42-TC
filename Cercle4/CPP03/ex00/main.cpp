/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:08 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:13 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap JeanJean("JeanJean");
	ClapTrap Bonjour("Bonjour");

	JeanJean.present_yourself();
	Bonjour.present_yourself();
	JeanJean.beRepaired(30);
	JeanJean.attack("Bonjour");
	Bonjour.takeDamage(JeanJean.get_attack());
	JeanJean.present_yourself();
	Bonjour.present_yourself();
	JeanJean.set_attack(25);
	JeanJean.present_yourself();
	JeanJean.attack("Bonjour");
	Bonjour.takeDamage(JeanJean.get_attack());
	JeanJean.present_yourself();
	Bonjour.present_yourself();
	Bonjour.attack("JeanJean");
	Bonjour.beRepaired(10);
	ClapTrap new_challenger("new challenger");
	new_challenger.set_attack(9);
	new_challenger.attack("JeanJean");
	JeanJean.takeDamage(new_challenger.get_attack());
	JeanJean.present_yourself();
	for (int i = 0; i < 5; i++)
	{
		JeanJean.beRepaired(1);
		JeanJean.present_yourself();
	}
	JeanJean.beRepaired(30);
	JeanJean.present_yourself();
	JeanJean.beRepaired(30);
	JeanJean.present_yourself();
}
