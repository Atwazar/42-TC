/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:02:13 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 16:02:15 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		Weapon(const Weapon&);
		Weapon &operator=(const Weapon&);
		std::string& getType();
		void setType(std::string new_type);
};

#endif
