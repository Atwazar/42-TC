/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:08 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/12 16:28:44 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "contact.hpp"

Contact::Contact()
{
}

Contact::Contact(const std::string f, const std::string l,
		const std::string n, const std::string p, const std::string d) :
		first_name(f), last_name(l), nick_name(n),
		phone_number(p), darkest_secret(d)
{
}

Contact::~Contact()
{
}

Contact::Contact(const Contact& c):first_name(c.first_name), last_name(c.last_name),
nick_name(c.nick_name),phone_number(c.phone_number),darkest_secret(c.darkest_secret)
{
}

Contact & Contact::operator= (const Contact& contact)
{
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->nick_name = contact.nick_name;
	this->phone_number = contact.phone_number;
	this->darkest_secret = contact.darkest_secret;
	return *this;
}

void Contact::print_contact()
{
	std::cout << "1.first name:\t\t";
	std::cout << this->first_name << std::endl;
	std::cout << "2.last name:\t\t";
	std::cout << this->last_name << std::endl;
	std::cout << "3.nick name:\t\t";
	std::cout <<  this->nick_name << std::endl;
	std::cout << "4.phone number:\t\t";
	std::cout << this->phone_number << std::endl;
	std::cout << "5.darkest secret:\t";
	std::cout << this->darkest_secret << std::endl;
	std::cout << "\n";
}

std::string Contact::get_first()
{
	return this->first_name;
}

std::string Contact::get_last()
{
	return this->last_name;
}

std::string Contact::get_nick()
{
	return this->nick_name;
}
