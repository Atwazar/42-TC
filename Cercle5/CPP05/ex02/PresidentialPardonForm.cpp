/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:16:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/20 17:16:06 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("unamned", 25, 5, "some random dude")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form):AForm(form)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradetoExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw Bureaucrat::FormNotSignedException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
	<< std::endl;
}
