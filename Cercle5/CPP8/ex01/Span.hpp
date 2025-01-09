/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:36:05 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/27 16:36:06 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


#define SPAN_FULLED "Span is at full capacity already"
#define MISSING_ELEMENT "There's not enought element to make a comparaison"

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span &operator=(const Span& other);

		std::vector<int> getSpan() const;

		void addNumber(int n);

		void addList(int *n, int size);

		long shortestSpan();
		long longestSpan();

		class	SpanFulled : public std::exception {
			public:
				const char	*what() const throw();
		};

		class	MissingElement : public std::exception {
			public:
				const char	*what() const throw();
		};

	private:
		std::vector<int> _span;
};

std::ostream& operator<<(std::ostream& o, const Span& span);
