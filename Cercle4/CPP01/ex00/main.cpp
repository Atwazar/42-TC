/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:48:48 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:48:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

class Zombie;

int main(void)
{
	Zombie dude;
	Zombie roland("roland");
	Zombie michel("michel");
	Zombie *new_zombie;
	michel.announce();
	roland.announce();
	dude.announce();
	new_zombie = newZombie("i'm a new zombie");
	new_zombie->announce();
	delete (new_zombie);
	randomChump("i'm a chump");
}
