/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:35:31 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:33 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria()
{
	_type = "AMateria";
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& AMateria):_type(AMateria._type)
{
	std::cout << "cloning of an AMateria" << std::endl;
}

AMateria &AMateria::operator=(const AMateria& AMateria)
{
	std::cout << "cloning of an AMateria using '='" << std::endl;
	_type = AMateria._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
