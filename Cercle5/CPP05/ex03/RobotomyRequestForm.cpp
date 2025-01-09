/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:42:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 14:42:06 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("unamned", 72, 45, "some random dude")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form):AForm(form)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getGradetoExec() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (!this->getSigned())
		throw Bureaucrat::FormNotSignedException();
	std::cout << "*Makes some drilling noises*"
	<< std::endl;
	int result = rand() % 2;
	if (result == SUCCESS)
		std::cout << getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}
