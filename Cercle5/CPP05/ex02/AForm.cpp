/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:23:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/20 12:23:29 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_grade_to_sign(150), _grade_to_exec(150)
{
	_name = "unamned";
	_signed = false;
	_target = "some random dude";
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target):
_grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _target(target)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw Bureaucrat::GradeTooLowException();
	_name = name;
	_signed = false;
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& other):_grade_to_sign(other._grade_to_sign),
_grade_to_exec(other._grade_to_sign)
{
	_name = other._name;
	_signed = other._signed;
}

AForm &AForm::operator=(const AForm& other)
{
	_name = other._name;
	_signed = other._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}
bool AForm::getSigned() const
{
	return (_signed);
}
int AForm::getGradetoSign() const
{
	return (_grade_to_sign);
}

int AForm::getGradetoExec() const
{
	return (_grade_to_exec);
}

std::string AForm::getTarget() const
{
	return (_target);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Bureaucrat::GradeTooLowException();
	if (_signed)
		throw Bureaucrat::FormAlreadySigned();
	_signed = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
	std::string sign;
	form.getSigned()==true ? sign = "":sign = "not ";
	o << "form \'" << form.getName() << "\' grade to sign it is " << form.getGradetoSign()
	<< ", grade to exec it is " << form.getGradetoExec()
	<< ", the file is now " << sign << "signed" << std::endl;
	return (o);
}
