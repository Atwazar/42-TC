/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:23:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 15:23:56 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void start_the_programm(void)
{
	std::cout << "Welcome to the Phonebook Program\n";
	std::cout << "here's a list of your available options:\n";
	std::cout << "\t1.Type \"ADD\" to add a new contact\n";
	std::cout << "\t2.Type \"SEARCH\" to search for a specific contact\n";
	std::cout << "\t3.Type \"EXIT\" to exit the program\n";
	std::cout << "choice is yours\n";
}
void display_info(void)
{
	std::cout << "1.ADD\t2.SEARCH\t3.EXIT\n";
}

void add_contact(void)
{
	std::cout << "adding contact\n";
}

void search_contact(void)
{
	std::cout << "searching contact\n";
}

void redirect_to_command(std::string input, PhoneBook *phonebook)
{
	if (input == "ADD")
		add_contact(), phonebook->add_contact(), display_info();
	else if (input == "SEARCH")
		search_contact(), phonebook->search_contact(), display_info();
	else if (input == "EXIT")
	{
		std::cout << "Goodbye.\n";
		exit(0);
	}
	else if (input == "REDISPLAY")
	{
		display_info();
	}
	// else if (input == "FILL_TEST")
	// {
	// 	phonebook->fill_test(), display_info();

	// }
	else
	{
		std::cout << "command \'" << input << "\' does not exist" << std::endl;
	}
}

int main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	start_the_programm();
	display_info();
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Goodbye.\n";
			exit(0);
		}
		redirect_to_command(input, &phonebook);
	}
}
