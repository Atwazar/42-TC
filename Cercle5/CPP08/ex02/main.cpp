/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:36:35 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/27 18:36:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "personnal tests"<< std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("salut");
		mstack.push("bonjour");
		mstack.push("coucou");
		mstack.push("hey");
		mstack.push("hello");
		mstack.push("plus d'inspi");

		MutantStack<std::string> mstack1(mstack);
		MutantStack<std::string> mstack2 = mstack;
		std::cout << std::endl << "affiche la stack cree normalement" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << "|";
		std::cout << std::endl;
		std::cout << std::endl << "affiche la stack cree par copie" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack1.begin(); it != mstack1.end(); it++)
			std::cout << *it << "|";
		std::cout << std::endl;
		std::cout << std::endl << "affiche la stack avec operateur =" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack2.begin(); it != mstack2.end(); it++)
			std::cout << *it << "|";
		std::cout << std::endl;

		MutantStack<std::string>::iterator it = mstack.begin();
		std::cout <<*(it) << std::endl;
		std::cout <<*(++it) << std::endl;
		std::cout <<*(it++) << std::endl;
		std::cout <<*(it) << std::endl;
		std::cout <<*(--it) << std::endl;
		std::cout <<*(it--) << std::endl;
	}
	std::cout << std::endl << "test provided by exercise" << std::endl;
	{
		std::cout << "testing with list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << *(--mstack.end()) << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}
	{
	std::cout << std::endl << "testing with MutantStack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
	}
}
