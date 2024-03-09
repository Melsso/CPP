/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:24:23 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:40:20 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <exception>

class BitcoinExchange {
	private:
		std::map<std::string, double> map;
	public:
		BitcoinExchange(const std::string &fname);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cp);
		BitcoinExchange &operator=(const BitcoinExchange &member);
		void readFile(const std::string &fname);
		void populate_map(void);
		bool DateParser(std::string &date);
		void parseLine(const std::string &line);
		
		class InvalidFile : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NegativeNumber : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class NumberTooBig : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class InvalidHeader : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
