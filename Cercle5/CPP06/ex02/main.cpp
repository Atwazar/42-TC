/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:23 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/22 17:34:24 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

#define TYPE_A 0
#define TYPE_B 1
#define TYPE_C 2
#define NBR_BASE_TYPE 3


Base * generate(void)
{
	int type = rand() % NBR_BASE_TYPE;
	switch(type)
	{
		case (TYPE_A):
		{
			std::cout << "has generated a Base type A" << std::endl;
			return (new A());
		}
		case (TYPE_B):
		{
			std::cout << "has generated a Base type B" << std::endl;
			return (new B());
		}
		case (TYPE_C):
		{
			std::cout << "has generated a Base type C" << std::endl;
			return (new C());
		}
	}
	return (0);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "type is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type is C" << std::endl;
}

void identify(Base& p)
{
	Base usuless;
	Base& garbage = usuless;
	try
	{
		garbage = dynamic_cast<A &>(p);
		std::cout << "type is A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			garbage = dynamic_cast<B &>(p);
			std::cout << "type is B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				garbage = dynamic_cast<C &>(p);
				std::cout << "type is C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "this is weird";
			}
		}
	}
}

int main ()
{
	srand((unsigned int)time(0));
	for (int i = 0; i < 10; i++)
	{
		Base *test = generate();
		identify(test);
		Base& ref = *test;
		identify(ref);
		delete test;
	}

}

