/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:44:34 by thelaine          #+#    #+#             */
/*   Updated: 2024/09/28 15:44:36 by thelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(DATA_CSV);

	if (!file.is_open())
	{
		std::cout << "file \'" << DATA_CSV << "\' cant be opened" << std::endl;
		throw Error();
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		double price = strtod(line.substr(line.find(',') + 1, line.length()).c_str(), 0);
		_map.insert(std::pair<std::string, double>(date, price));
	}
}
BitcoinExchange::~BitcoinExchange()
{

}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
{
	_map = other._map;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & other)
{
	_map = other._map;
	return (*this);
}

std::map<std::string, double> BitcoinExchange::getMap()
{
	return (_map);
}

int BitcoinExchange::valid_format(std::string line)
{
	if (line.length() < 14)
		return INPUT_FORMAT_INVALID;
	std::string date = line.substr(0, 10);
	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return INVALID_DATE;
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return INPUT_FORMAT_INVALID;
	int has_dot = 0;
	for (unsigned long i = 13; i < line.length(); i++)
	{
		if (line[i] == '.')
		{
			if (has_dot++ == 1)
				return INVALID_NUMBER;
		}
		else if (!isdigit(line[i]))
			return INVALID_NUMBER;
	}
	float value = atof(&line.c_str()[13]);
	if (value > 1000)
		return (INVALID_NUMBER);
	return CORRECT_INPUT;
}

void BitcoinExchange::get_bad_display(std::string line, int error_code)
{
	(void) line;
	switch(error_code)
	{
		case INPUT_FORMAT_INVALID:
		{
			std::cout << "Error:the format is not respecting \"date | value\" with value being made of digits only" << std::endl;
			return;
		}
		case INVALID_DATE:
		{
			std::cout << "Error: date doesnt have correct format YYYY-MM-DD" << std::endl;
			return;
		}
		case INVALID_NUMBER:
		{
			std::cout << "Error: value doesnt respect 0 < X < 1000" << std::endl;
			return;
		}
		case TOO_EARLY:
		{
			std::cout << "Error: not even sure bitcoin was existing at the time.. wyd" << std::endl;
			return;
		}
	}
}

void BitcoinExchange::get_good_display(std::string date, double quantity, double price)
{
	std::cout << date << " => " << quantity << " * " << price << " = " << quantity * price
	<< std::endl;
}

void BitcoinExchange::do_the_job(std::string file_name)
{
	std::ifstream file(file_name.c_str());

	if (!file.is_open())
	{
		std::cout << "file \'" << file_name << "\' cant be opened" << std::endl;
		throw Error();
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
			int format = valid_format(line);
			// std::cout << "word is " << line << " and format is " <<  format <<  std::endl;
			if (format != CORRECT_INPUT)
			{
				get_bad_display(line, format);
				continue;
			}
			// std::cout << "are we here someday" << std::endl;
			std::string date = line.substr(0, 10);
			float quantity = atof(&line.c_str()[13]);
			if (date < _map.begin()->first)
			{
				get_bad_display(line, TOO_EARLY);
				continue;
			}
			std::map<std::string, double>::iterator pos = _map.find(date);
			if (pos == _map.end())
			{
				// std::cout << "we are here arent we" << std::endl;
				pos = _map.lower_bound(date);
				pos--;
			}
			// std::cout << "date is " << date << " and date_ref is " << pos->first << std::endl;
			double price = pos->second;
			get_good_display(date, quantity, price);
		}
	}


// std::map<std::string, double> create_map(const char* file_name)
// {
// 	std::string file_read;
// 	char		char_read;
// 	std::ifstream file_in(file_name);
// 	if (!file_in)
// 	{
// 		std::cout << "error during file openning" << std::endl;
// 		return NULL;
// 	}
// 	file_read = "";
// 	while (file_in.get(char_read))
// 		file_read += char_read;

// }

