/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:21:38 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/19 14:21:40 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern timmy;

	AForm *form_test = timmy.makeForm("P", "poor_timmy");
	(void)form_test;
	std::string poor_timmy = "poor timmy";
	{
		std::cout << "testing perdon form" << std::endl;
		Bureaucrat Perdon_sign("jeanjean", 26);
		Bureaucrat Perdon_exec("jojo", 6);
		AForm *form_perdon = timmy.makeForm(PARDON_REQUEST, "poor_timmy");
		Perdon_exec.executeForm(*form_perdon);
		Perdon_exec.promotion();
		Perdon_exec.executeForm(*form_perdon);
		Perdon_sign.signForm(*form_perdon);
		Perdon_sign.promotion();
		Perdon_sign.signForm(*form_perdon);
		Perdon_exec.executeForm(*form_perdon);
		delete form_perdon;
	}
	{
		srand((unsigned int)time(0));
		std::cout << "testing Robotomy form" << std::endl;
		Bureaucrat Robotomy_sign("jeanjean", 73);
		Bureaucrat Robotomy_exec("jojo", 46);
		AForm *form_Robotomy = timmy.makeForm(ROBOTOMY_REQUEST, "poor_jimmy");
		Robotomy_exec.executeForm(*form_Robotomy);
		Robotomy_exec.promotion();
		Robotomy_exec.executeForm(*form_Robotomy);
		Robotomy_sign.signForm(*form_Robotomy);
		Robotomy_sign.promotion();
		Robotomy_sign.signForm(*form_Robotomy);
		Robotomy_exec.executeForm(*form_Robotomy);
		delete form_Robotomy;
	}
	{
		std::cout << "testing Shrubbery form" << std::endl;
		Bureaucrat Shrubbery_sign("jeanjean", 146);
		Bureaucrat Shrubbery_exec("jojo", 138);
		AForm *form_Shrubbery= timmy.makeForm(SHRUBBERY_REQUEST, "poor_mimmy");
		Shrubbery_exec.executeForm(*form_Shrubbery);
		Shrubbery_exec.promotion();
		Shrubbery_exec.executeForm(*form_Shrubbery);
		Shrubbery_sign.signForm(*form_Shrubbery);
		Shrubbery_sign.promotion();
		Shrubbery_sign.signForm(*form_Shrubbery);
		Shrubbery_exec.executeForm(*form_Shrubbery);
		delete form_Shrubbery;
	}
	return (0);
}
