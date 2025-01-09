/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:48 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:49 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		HumanB(const HumanB&);
		HumanB &operator=(const HumanB&);
		void setWeapon(Weapon weapon);
		void attack();
};

#endif
