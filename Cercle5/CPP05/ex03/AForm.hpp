/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm
{
	public:
		AForm();
		AForm(std::string name, int grade_to_sign, int grade_to_exec, std::string target);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);

		std::string getName() const;
		bool getSigned() const;
		int getGradetoSign() const;
		int getGradetoExec() const;
		std::string getTarget() const;

		void beSigned(Bureaucrat const & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;


	private:
		std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_exec;
		std::string _target;
};

std::ostream& operator<<(std::ostream& o, const AForm& form);
