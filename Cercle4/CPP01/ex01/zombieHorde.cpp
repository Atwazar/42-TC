/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:19 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:20 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie_horde;
	zombie_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie_horde[i].change_name(name);
	return zombie_horde;
}
