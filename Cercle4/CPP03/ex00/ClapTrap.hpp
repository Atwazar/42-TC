/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		~ClapTrap(void);
		ClapTrap(std::string Name);
		ClapTrap();
		ClapTrap &operator=(const ClapTrap&);
		ClapTrap(const ClapTrap&);


		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void set_attack(unsigned int new_attack);
		unsigned int get_attack(void);
		std::string get_name(void);
		void present_yourself(void);
	private:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
		unsigned int max_hp;
};


#endif
