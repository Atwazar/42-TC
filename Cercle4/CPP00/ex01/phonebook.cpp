/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:23:54 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 15:23:56 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include.hpp"
#include "phonebook.hpp"
#include "contact.hpp"
#include <string>

PhoneBook::PhoneBook()
{
	this->len = 0;
}

PhoneBook::~PhoneBook()
{

}

PhoneBook::PhoneBook(const PhoneBook& phonebook):contacts(phonebook.contacts),
len(phonebook.len)
{

}

int	PhoneBook::invalid_phone_number(std::string s)
{
	if (s.length() != 10)
		return (1);
	if (s[0] != '0')
		return (1);
	return (0);
}

void PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "fill the following fields to add a contact:\n";
	std::cout << "1.first name:\t\t";
	getline(std::cin, first_name);
	if (first_name == "")
	{
		std::cout << "no first name entered, abort" << std::endl;
		return ;
	}
	std::cout << "2.last name:\t\t";
	getline(std::cin, last_name);
	if (last_name == "")
	{
		std::cout << "no last name entered, abort" << std::endl;
		return ;
	}
	std::cout << "3.nick name:\t\t";
	getline(std::cin, nick_name);
	if (nick_name == "")
	{
		std::cout << "no nick name entered, abort" << std::endl;
		return ;
	}
	std::cout << "4.phone number:\t\t";
	getline(std::cin, phone_number);
	if (phone_number == "" || invalid_phone_number(phone_number))
	{
		std::cout << "invalid phone_number entered, abort" << std::endl;
		return ;
	}
	std::cout << "5.darkest secret:\t";
	getline(std::cin, darkest_secret);
	if (darkest_secret == "")
	{
		std::cout << "no darkest secret entered, abort" << std::endl;
		return ;
	}

	if (this->len == 8)
	{
		this->contacts[0] = this->contacts[1];
		this->contacts[1] = this->contacts[2];
		this->contacts[2] = this->contacts[3];
		this->contacts[3] = this->contacts[4];
		this->contacts[4] = this->contacts[5];
		this->contacts[5] = this->contacts[6];
		this->contacts[6] = this->contacts[7];
		this->contacts[7] = Contact(first_name, last_name,
			nick_name, phone_number, darkest_secret);
	}
	else
	{
		this->contacts[this->len] = Contact(first_name, last_name,
			nick_name, phone_number, darkest_secret);
			this->len++;
	}
}
PhoneBook &PhoneBook::operator=(const PhoneBook& phonebook)
{
	this->len = phonebook.len;
	for (int i = 0; i<this->len;i++)
		this->contacts[i] = phonebook.contacts[i];
	return *this;
}

static std::string get_good_display(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		while(str.length() < 10)
			str = " " + str;
	return (str);
}

void PhoneBook::search_contact()
{
	std::string input;

	if (this->len == 0)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << " ___________________________________________\n"
			 << "|     index|first_name| last_name| nick_name|\n"
			 << "|__________|__________|__________|__________|\n";
	for (int i = 0; i < this->len; i++)
		std::cout << "|" << "         " << i + 1 << "|"
				<< get_good_display(this->contacts[i].get_first()) << "|"
				<< get_good_display(this->contacts[i].get_last()) << "|"
				<< get_good_display(this->contacts[i].get_nick()) << "|"
				<< std::endl;
	std::cout << "|__________|__________|__________|__________|\n\n";
	std::cout << "type an index to see more detail,"
			<< " anything else will bring you back to the menu\n";
	getline(std::cin, input);
	if (input == "")
		return ;
	if (input.length() == 1 && (input[0] - 48 > 0 && input[0] - 48 < this->len + 1))
		this->contacts[input[0] - 48 - 1].print_contact();
	else
		std::cout << "incorrect index, going back to the menu\n";
}

void PhoneBook::fill_test()
{
	this->len = 8;
	this->contacts[0] = Contact("Jean", "Jean", "Jeanjean", "0123456789", "cant swim");
	this->contacts[1] = Contact("Morgan", "James", "MJ", "9876543210", "cant drive");
	this->contacts[2] = Contact("Mike", "Mouse", "Mickey Mouse", "24680939828", "cant fly");
	this->contacts[3] = Contact("Dominique", "Hawk", "Dom-dom", "012156789", "cant do shit");
	this->contacts[4] = Contact("Alexandracofeu", "Klake", "dracofeu", "120123456789", "just cant");
	this->contacts[5] = Contact("Donald", "Duck", "Donald obviously", "0146200001", "wish he had a darkest secret");
	this->contacts[6] = Contact("geting", "tired of this", "come on", "0123456789", "cant swim can he");
	this->contacts[7] = Contact("the last one", "for lord sake", "over", "1123456789", "cant do this anymore");
}
