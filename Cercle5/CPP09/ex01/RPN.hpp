/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:59:17 by thelaine          #+#    #+#             */
/*   Updated: 2024/10/01 15:59:18 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <stack>
#include <limits.h>

#define NOTHING -1
#define NULL_CHAR '\0'
#define ONE 1
#define PLUS 10
#define MINUS 11
#define TIME 12
#define DIVIDE 13
#define TAR 10
#define NBR_OF_DIGIT 10
#define NBR_ACCEPTED_CHAR 14
#define SPACE 32


#define PERSISTANT_TESTER "damn you're so persistant, but this is not an int anymore"
#define NOT_A_GOOD_CHAR "you have an intruder among the chars"
#define TOO_MUCH_OPERATOR "there is too many operator at some point to make it work"
#define SPACE_NEEDED "space is needed between every char"
#define OPERATOR_MISSING "there must be some operator missing to make it right"
#define SACRILEGIOUS "stop whatever it is that you are doing, this is unacceptable"


class	Error : public std::exception {
	private:
		std::string _message;
	public:
		Error(const char *message): _message(message) {}
		Error(const std::string &message): _message(message) {}
		const char *what() const throw();
		~Error() throw(){};
};

void do_the_rpn(char *str);
