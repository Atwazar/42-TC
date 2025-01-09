/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:44:34 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/28 15:44:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
#include <ctime>

#define DATA_CSV "data.csv"

#define CORRECT_INPUT 0
#define INPUT_FORMAT_INVALID 1
#define INVALID_DATE 2
#define INVALID_NUMBER 3
#define TOO_EARLY 4

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange &operator=(const BitcoinExchange & other);

		std::map<std::string, double> getMap();

		int valid_format(std::string line);

		void do_the_job(std::string file_name);

		void get_bad_display(std::string line, int error_code);
		void get_good_display(std::string date, double quantity, double price);

			class Error : public std::exception{};


	private:
		std::map<std::string, double> _map;
};
