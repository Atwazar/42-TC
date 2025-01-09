/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:10 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:11 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl()
{
}

Harl::Harl(const Harl& harl)
{
}

Harl &Harl::operator=(const Harl& harl)
{
	return (*this);
}

Harl::~Harl(void)
{
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-"
	<< "ketchup burger. I really do!" << std::endl;

}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs"
	<< " more money. You didn’t put enough bacon in my burger!"
	<< " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years whereas you started working here "
	<< "since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	for (i; i < 4; i++)
	{
		if (level == this->levels[i])
			break;
	}
	if (i == 4)
		return;
	for (int j = 0; j <= i; j++)
		(this->*actions[j])();
}
