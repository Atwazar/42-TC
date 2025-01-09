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
	Zombie *zombie_horde;
	int N = 3;
	zombie_horde = zombieHorde(N, "i'm part of the Horde");
	for (int i = 0; i < N; i++)
		zombie_horde[i].announce();
	delete [] zombie_horde;
}
