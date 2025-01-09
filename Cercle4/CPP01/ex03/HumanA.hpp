/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:39 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:40 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		HumanA(const HumanA&);
		HumanA &operator=(const HumanA&);
		void setWeapon(Weapon weapon);
		void attack();
};

#endif
