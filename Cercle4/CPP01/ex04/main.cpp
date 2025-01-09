/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:48:48 by thelaine          #+#    #+#             */
/*   Updated: 2024/08/14 17:48:51 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string replace;
	std::string total_file;
	std::string saved_string;
	char		char_read;

	if (ac != 4)
	{
		std::cout << "this is not the appropriate number of arguments"
		<< std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	replace = filename + ".replace";


	while(total_file.rfind(s1) != -1)
	{
		saved_string = total_file.substr(0, total_file.rfind(s1));
		saved_string += s2;
		saved_string += total_file.substr(total_file.rfind(s1) + s1.length(),
		total_file.length() - total_file.rfind(s1) + s1.length());
		total_file = saved_string;
	}
	file_out << total_file;
	return (0);
}
