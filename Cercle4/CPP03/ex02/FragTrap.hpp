/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:19:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/19 12:19:30 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP

# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		~FragTrap(void);
		FragTrap(std::string Name);
		FragTrap();
		FragTrap &operator=(const FragTrap&);
		FragTrap(const FragTrap&);

		void highFivesGuys(void);
		void attack(const std::string& target);
};

#endif
