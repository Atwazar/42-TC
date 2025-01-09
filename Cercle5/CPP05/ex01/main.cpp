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

int main(void)
{
	try
	{
		Form form_1("form_1", 250, 50);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Form form_1("form_1", 0, 10);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Form form_1("form_1", 10, 250);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Form form_1("form_1", 10, 0);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	Bureaucrat Jeanjean("jeanjean", 10);
	Form form_1("form_1", 9, 50);
	std::cout << form_1;
	Form& ref = form_1;
	Jeanjean.signForm(ref);
	std::cout << form_1;
	Jeanjean.promotion();
	Jeanjean.signForm(ref);
	std::cout << form_1;
	Jeanjean.signForm(ref);
	std::cout << form_1;

}
