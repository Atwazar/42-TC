/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:10:11 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/15 15:13:47 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iostream"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "adress of str: " << &str << std::endl;
	std::cout << "adress of strPTR: " << strPTR << std::endl;
	std::cout << "adress of strREF: " << &strREF << std::endl;
	std::cout << "value of str: " << str << std::endl;
	std::cout << "value of strPTR: " << *strPTR << std::endl;
	std::cout << "value of strREF: " << strREF << std::endl;
}
