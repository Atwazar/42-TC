/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap,public FragTrap
{
	public:
		~DiamondTrap(void);
		DiamondTrap(std::string Name);
		DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap&);
		DiamondTrap(const DiamondTrap&);

		void WhoAmI(void);
		void attack(const std::string& target);

	private:
		std::string name;


};

#endif
