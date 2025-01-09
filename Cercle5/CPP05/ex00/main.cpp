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
		Bureaucrat Jeanjean("jeanjean", 250);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Bureaucrat Jeanjean("jeanjean", 0);
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Bureaucrat Jeanjean("jeanjean", 1);
		std::cout << Jeanjean;
		Jeanjean.promotion();
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Bureaucrat Michmich("jeanjean", 150);
		std::cout << Michmich;
		Michmich.retrogradation();
		std::cout << Michmich;
		std::cout << "it worked, so it didnt" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it did" << std::endl;
	}
	try
	{
		Bureaucrat Jojo("jojo", 78);
		std::cout << Jojo;
		Jojo.retrogradation();
		std::cout << Jojo;
		Jojo.promotion();
		std::cout << Jojo;
		std::cout << "it worked, so it did" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		std::cout << "didnt work, so it didnt" << std::endl;
	}
}
