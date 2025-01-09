/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:01:44 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 15:01:45 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("unamned", 145, 137, "some random dude")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form):AForm(form)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradetoExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw Bureaucrat::FormNotSignedException();
	std::string std_file_name = getTarget() + "_shrubbery";
	const char *char_file_name = std_file_name.c_str();
	std::ofstream shrubbery(char_file_name);
	if (!shrubbery)
		throw Bureaucrat::FileCreationErrorException();
	shrubbery << TREE << "\n\n" << TREE;
}
