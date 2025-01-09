/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:49:02 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:49:03 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
	public:
		void filter (std::string level);
		Harl();
		~Harl();

	private:
		void debug();
		void info();
		void warning();
		void error();
		Harl &operator=(const Harl&);
		Harl(const Harl&);
		std::string levels[4] = {"DEBUG","INFO", "WARNING", "ERROR"};
		void (Harl::* actions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
};

#endif

