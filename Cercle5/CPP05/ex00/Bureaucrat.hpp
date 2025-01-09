/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:22:10 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/19 14:22:12 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

# define TOO_HIGH "Grade is too high\n"

# define TOO_LOW "Grade is too low\n"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat (const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		void promotion();
		void retrogradation();

		std::string getName() const;
		int getGrade() const;

		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
			};
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat);


