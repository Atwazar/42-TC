/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:05:06 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 13:05:08 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP

# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"


class Ice : public AMateria
{
	public:
		virtual ~Ice();
		Ice();
		Ice &operator=(const Ice&);
		Ice(const Ice&);

		std::string const & getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
	protected:
		std::string type;
};

#endif
