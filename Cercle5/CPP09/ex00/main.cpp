/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:24:56 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/26 17:24:57 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

void print_container(std::map<std::string, double> it)
{
	for(std::map<std::string, double>::iterator i = it.begin(); i!=it.end(); i++)
		std::cout << i->first << "|" << i->second << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "one argument and one only is required" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange transformer;
		// print_container(transformer.getMap());
		transformer.do_the_job(av[1]);
	}
	catch (std::exception &e)
	{
		return (1);
	}

	return (0);


}
