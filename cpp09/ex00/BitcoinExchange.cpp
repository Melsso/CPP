/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:24:44 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:24:30 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &fname) {
	try {
		populate_map();
		readFile(fname);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return ;
	}
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp) : map(cp.map) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &member) {
	if (this != &member) {
		this->map = member.map;
	}
	return *this;
}

bool BitcoinExchange::DateParser(std::string &date) {
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1)
		return false;
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				return false;
			break ;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				if (day > 29)
					return false;
			}
			else if (day > 28)
				return false;
			break ;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				return false;
			break ;
	}
	return true;
}

void BitcoinExchange::populate_map(void) {
	std::ifstream f("data.csv");
	if (!f.is_open())
		throw InvalidFile();

	std::string line;
	std::string date;
	double		val;
	size_t		pos;

	std::getline(f, line);
	if (line != "date,exchange_rate") {
		f.close();
		throw InvalidHeader();
	}
	while (std::getline(f, line)) {
		
		pos = line.find(",");
		if (pos != std::string::npos) {
			date = line.substr(0, pos);
			val = std::stod(line.substr(pos + 1));
			this->map.insert(std::pair<std::string, double>(date, val));
		}
	}
}

void BitcoinExchange::parseLine(const std::string &line) {
	size_t		pos;
	std::string date;
	double		val;

	pos = line.find("|");
	if (pos == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	date = line.substr(0, pos - 1);
	if (DateParser(date) == false) {
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	
	val = std::stod(line.substr(pos + 1));
	if (val < 0)
		throw NegativeNumber();
	if (val > 1000)
		throw NumberTooBig();

	std::map<std::string, double>::iterator it = this->map.lower_bound(date);
	if (it == this->map.end())
		--it;
	std::cout << date << " => " << val << " = " << it->second * val << std::endl;
}

void BitcoinExchange::readFile(const std::string &fname) {

	std::ifstream f(fname);
	if (!f.is_open())
		throw InvalidFile();

	std::string line;
	std::getline(f, line);
	if (line != "date | value")
		throw InvalidHeader();
	while (std::getline(f, line)) {
		try {
			parseLine(line);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	f.close();
}

const char* BitcoinExchange::InvalidFile::what() const throw() {
	return "could not open file.";
}

const char* BitcoinExchange::InvalidHeader::what() const throw() {
	return "Invalid header!";
}

const char* BitcoinExchange::NegativeNumber::what() const throw() {
	return "not a positive number.";
}

const char* BitcoinExchange::NumberTooBig::what() const throw() {
	return "too large a number.";
}
