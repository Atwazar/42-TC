/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:43:21 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 16:43:21 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int i;
	std::string forms[3] = {ROBOTOMY_REQUEST, PARDON_REQUEST, SHRUBBERY_REQUEST};
	for (i = 0; i < NBR_OF_DIFFERENT_FORMS; i++)
	{
		if (forms[i] == name)
			break;
	}
	if (i == NBR_OF_DIFFERENT_FORMS)
	{
		std::cout << "this form doesn't exist, unfortunately" << std::endl;
		return (NULL);
	}
	switch (i)
	{
		case (ROBOTOMY):
			return (new RobotomyRequestForm(target));
		case (PARDON):
			return (new PresidentialPardonForm(target));
		case (SHRUBBERY):
			return (new ShrubberyCreationForm(target));
	}
	return (NULL);
}
