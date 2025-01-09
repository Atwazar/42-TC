/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:13 by thelaine          #+#    #+#             */
/*   Updated: 2024/10/01 15:59:14 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

char charset[NBR_ACCEPTED_CHAR] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'+', '-', '*', '/'};

const char *Error::what() const throw()
{
	return (_message.c_str());
}

static int is_interesting(char c)
{
	for (int i = 0; i < NBR_ACCEPTED_CHAR; i++)
	{
		if (c == charset[i])
			return (i);
	}
	return (NOTHING);
}

static int plus(long a, long b)
{
	if (a + b > INT_MAX || a + b < INT_MIN)
		throw Error(PERSISTANT_TESTER);
	return (a + b);
}

static int minus(long a, long b)
{
	if (b - a > INT_MAX || b - a < INT_MIN)
		throw Error(PERSISTANT_TESTER);
	return (b - a);
}

static int time(long a, long b)
{
	if (a * b > INT_MAX || a * b < INT_MIN)
		throw Error(PERSISTANT_TESTER);
	return (a * b);
}

static int divide(long a, long b)
{
	if (!a)
		throw Error(SACRILEGIOUS);
	return (b / a);
}

int (*operations[4])(long, long) = {plus, minus, time, divide};


static void deal_with_operator(int operatotor, std::stack<long> &stackas)
{
	if (stackas.size() < 2)
		throw Error(TOO_MUCH_OPERATOR);
	try
	{
		long a = stackas.top();
		stackas.pop();
		long b = stackas.top();
		stackas.pop();
		long result = operations[operatotor - TAR](a, b);
		// std::cout << result << std::endl;
		stackas.push(result);
	}
	catch(const std::exception& e)
	{
		throw Error(e.what());
	}

}

void do_the_rpn(char *str)
{
	std::stack<long> stackas;
	int actual_char;
	try
	{
		while (*str)
		{
			actual_char = is_interesting(*str);
			if (actual_char == NOTHING)
				throw Error(NOT_A_GOOD_CHAR);
			else if (actual_char < NBR_OF_DIGIT)
				stackas.push(actual_char);
			else
			{
				try
				{
					deal_with_operator(actual_char, stackas);
				}
				catch (std::exception &e)
				{
					throw Error(e.what());
				}
			}
			if (*(++str) && *str != SPACE)
				throw Error(SPACE_NEEDED);
			if (*str)
				str++;
		}
		if (stackas.size() != 1)
			throw Error(OPERATOR_MISSING);
		std::cout << stackas.top() << std::endl;
	}
	catch (const std::exception& e)
	{
		throw Error(e.what());
	}

}
