/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:49 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(const Cure& Cure):AMateria(Cure)
{
}

Cure &Cure::operator=(const Cure& Cure)
{
	_type = Cure.type;
	return *this;
}

std::string const & Cure::getType() const
{
	return (_type);
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
		std::cout << "* heals " << target.getName() << "'s wounds *"
		<< std::endl;
}
