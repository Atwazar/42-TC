/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:36:00 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/27 16:36:02 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span()
{
	_span.reserve(0);
}
Span::Span(unsigned int N)
{
	try
	{
		_span.reserve(N);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
Span::~Span()
{
}
Span::Span(const Span& other)
{
	_span = other._span;
}

Span &Span::operator=(const Span& other)
{
	_span = other._span;
	return (*this);
}

std::vector<int> Span::getSpan() const
{
	return (_span);
}
void Span::addNumber(int n)
{
	if (_span.size() == _span.capacity())
		throw SpanFulled();
	_span.push_back(n);
}

void Span::addList(int *n, int size)
{
	for (int i = 0; i < size; i++)
	{
		try
		{
			addNumber(n[i]);
		}
		catch(const std::exception& e)
		{
			throw SpanFulled();;
		}
	}
}

long Span::shortestSpan()
{
	if (_span.size() < 2)
		throw MissingElement();
	std::vector<int> sorted = _span;
	std::sort(sorted.begin(), sorted.end());
	long min_gap = *(sorted.end() - 1) - *sorted.begin();
	std::vector<int>::iterator a = sorted.begin();
	std::vector<int>::iterator b = a + 1;
	while (b != sorted.end())
	{
		if ((long)*b - (long)*a < min_gap)
			min_gap = *b - *a;
		a++;
		b++;
	}
	return (min_gap);
}

long Span::longestSpan()
{
	if (_span.size() < 2)
		throw MissingElement();
	std::vector<int> sorted = _span;
	std::sort(sorted.begin(), sorted.end());
	// for (std::vector<int>::iterator i = sorted.begin(); i != sorted.end(); i++)
	// 	std::cout << *i << "|";
	return (*(sorted.end() - 1) - *sorted.begin());
}

const char *Span::SpanFulled::what() const throw()
{
	return SPAN_FULLED;
}

const char *Span::MissingElement::what() const throw()
{
	return MISSING_ELEMENT;
}

std::ostream& operator<<(std::ostream& o, const Span& span)
{
	std::vector<int> vect = span.getSpan();
	for (std::vector<int>::iterator i = vect.begin(); i != vect.end(); i++)
		o << *i << "|";
	return o;
}
