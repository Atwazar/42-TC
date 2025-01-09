/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:
		~ScavTrap(void);
		ScavTrap(std::string Name);
		ScavTrap();
		ScavTrap &operator=(const ScavTrap&);
		ScavTrap(const ScavTrap&);

		void guardGate();
		void attack(const std::string& target);
};

#endif
