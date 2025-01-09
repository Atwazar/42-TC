/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:43:31 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 16:43:32 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NBR_OF_DIFFERENT_FORMS 3
#define ROBOTOMY 0
#define ROBOTOMY_REQUEST "robotomy request"
#define PARDON 1
#define PARDON_REQUEST "pardon request"
#define SHRUBBERY 2
#define SHRUBBERY_REQUEST "shrubbery request"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);
		AForm *makeForm(std::string name, std::string target);
};
