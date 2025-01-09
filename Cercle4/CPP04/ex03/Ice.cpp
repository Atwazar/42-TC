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

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::~Ice()
{
}

Ice::Ice(const Ice& Ice):AMateria(Ice)
{
}

Ice &Ice::operator=(const Ice& Ice)
{
	_type = Ice._type;
	return *this;
}

std::string const & Ice::getType() const
{
	return (_type);
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *"<< std::endl;
}
