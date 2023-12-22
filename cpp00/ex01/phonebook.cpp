/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:00:47 by smallem           #+#    #+#             */
/*   Updated: 2023/12/06 14:44:15 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool	Contact::get_fname(void) {
	std::cout << "Enter the first name" << std::endl;
	std::getline(std::cin, this->fname);	
	if (this->fname.empty())
		return (0);
	for (size_t i = 0; i < this->fname.length(); i++) {
		if (!std::isalpha(this->fname[i]) && this->fname[i] != ' ')
		{
			std::cout << "Invalid first name format" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::get_lname(void) {
	std::cout << "Enter the last name" << std::endl;
	std::getline(std::cin, this->lname);
	if (this->lname.empty())
		return (0);
	for (size_t i = 0; i < this->lname.length(); i++) {
		if (!std::isalpha(this->lname[i]) && this->lname[i] != ' ')
		{
			std::cout << "Invalid last name format" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::get_nname(void) {
	std::cout << "Enter the nickname" << std::endl;
	std::getline(std::cin, this->nname);
	if (this->nname.empty())
		return (0);
	for (size_t i = 0; i < this->nname.length(); i++) {
		if (!std::isalpha(this->nname[i]) && this->nname[i] != ' ')
		{
			std::cout << "Invalid nickname format" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::get_phonenbr(void) {
	std::cout << "Enter the phone number" << std::endl;
	std::getline(std::cin, this->phone);
	if (this->phone.empty())
		return (0);
	for (size_t i = 0; i < this->phone.length(); i++) {
		if (!std::isdigit(this->phone[i]))
		{
			std::cout << "Invalid phone number format" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::get_secret(void) {
	std::cout << "Enter the darkest secret" << std::endl;
	std::getline(std::cin, this->secret);
	if (this->secret.empty())
		return (0);
	for (size_t i = 0; i < this->secret.length(); i++) {
		if (!std::isalpha(this->secret[i]) && this->secret[i] != ' ')
		{
			std::cout << "Invalid secret format" << std::endl;
			return false;
		}
	}
	return true;
}

bool	Contact::fill_cont(void) {
	if (this->get_fname() && this->get_lname() && this->get_nname()
		&& this->get_phonenbr() && this->get_secret())
		return true;
	return false;
}
void	Contact::display_cont(int ind) {
	std::cout << std::setw(10) << std::right << ind << "|";
	if (this->fname.length() > 10)
		std::cout << std::setw(10) << std::right
			<< (this->fname.substr(0, 9) + ".") << "|";
	else
		std::cout << std::setw(10) << std::right << this->fname << "|";

	if (this->lname.length() > 10)
		std::cout << std::setw(10) << std::right
			<< (this->lname.substr(0, 9) + ".") << "|";
	else
		std::cout << std::setw(10) << std::right << this->lname << "|";
	if (this->nname.length() > 10)
		std::cout << std::setw(10) << std::right
			<< (this->nname.substr(0, 9) + ".") << "|" << std::endl;
	else
		std::cout << std::setw(10) << std::right << this->nname <<  "|" << std::endl;
}

void	Contact::display_all(void) {
	std::cout << "First Name: " << this->fname << std::endl;
	std::cout << "Last Name: " << this->lname << std::endl;
	std::cout << "Nickname: " << this->nname << std::endl;
	std::cout << "Phone Number: " << this->phone << std::endl;
	std::cout << "Darkest Secret: " << this->secret << std::endl;
}

void	PhoneBook::rotate(void) {
	for (int i = 0; i < this->n - 1; i++)
		cl[i] = cl[i + 1];
	this->n--;
}
