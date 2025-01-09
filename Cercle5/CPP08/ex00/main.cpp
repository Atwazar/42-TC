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

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <list>


template <typename T>
void print_container(T& it)
{
	for(typename T::iterator i = it.begin(); i!=it.end(); i++)
		std::cout << static_cast<int>(*i) << "|";
	std::cout << std::endl;
}

int main(void)
{
	{
	std::cout << "testing with vect" << std::endl;
	std::vector<int> vect;
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(5);
	print_container(vect);
	try{
	std::vector<int>::iterator j = easyfind(vect, 2);
	std::cout << *j << std::endl;
	j = easyfind(vect, 3);
	std::cout << *j << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "was not found" << std::endl;
	}
	}
	{
	std::cout << "testing with list" << std::endl;
	std::list<int> list;
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	print_container(list);
	try{
	std::list<int>::iterator j = easyfind(list, 2);
	std::cout << *j << std::endl;
	j = easyfind(list, 12);
	std::cout << *j << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "was not found" << std::endl;
	}
	}
}
