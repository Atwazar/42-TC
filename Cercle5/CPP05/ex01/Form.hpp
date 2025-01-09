/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:23:34 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/20 12:23:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_exec);
		~Form();
		Form(const Form& other);
		Form &operator=(const Form& other);

		std::string getName() const;
		bool getSigned() const;
		int getGradetoSign() const;
		int getGradetoExec() const;

		void beSigned(Bureaucrat const & bureaucrat);


	private:
		std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_exec;
};

std::ostream& operator<<(std::ostream& o, const Form& form);
