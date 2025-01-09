/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:22:06 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/19 14:22:07 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("unamned"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::promotion()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::retrogradation()
{
	if(_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couln't sign " << form.getName()
		<< " because " << e.what();
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return TOO_LOW;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return TOO_HIGH;
}

const char *Bureaucrat::FormAlreadySigned::what() const throw()
{
	return ALREADY_SIGNED;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat)
{
	o << bureaucrat.getName() << ", grade is " << bureaucrat.getGrade() << std::endl;
	return (o);
}
