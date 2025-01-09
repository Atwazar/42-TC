/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:23:28 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/20 12:23:29 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_grade_to_sign(150), _grade_to_exec(150)
{
	_name = "unamned";
	_signed = false;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec):_grade_to_sign(grade_to_sign),
 _grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw Bureaucrat::GradeTooLowException();
	_name = name;
	_signed = false;
}

Form::~Form()
{

}

Form::Form(const Form& other):_grade_to_sign(other._grade_to_sign),
_grade_to_exec(other._grade_to_sign)
{
	_name = other._name;
	_signed = other._signed;
}

Form &Form::operator=(const Form& other)
{
	_name = other._name;
	_signed = other._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}
bool Form::getSigned() const
{
	return (_signed);
}
int Form::getGradetoSign() const
{
	return (_grade_to_sign);
}

int Form::getGradetoExec() const
{
	return (_grade_to_exec);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw Bureaucrat::GradeTooLowException();
	if (_signed)
		throw Bureaucrat::FormAlreadySigned();
	_signed = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	std::string sign;
	form.getSigned()==true ? sign = "":sign = "not ";
	o << "form \'" << form.getName() << "\' grade to sign it is " << form.getGradetoSign()
	<< ", grade to exec it is " << form.getGradetoExec()
	<< ", the file is now " << sign << "signed" << std::endl;
	return (o);
}
