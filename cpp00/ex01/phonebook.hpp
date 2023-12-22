/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:47:43 by smallem           #+#    #+#             */
/*   Updated: 2023/12/11 15:38:48 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cctype>
#include <iostream>
#include <iomanip>
#include <limits>

class Contact {
	private:
	std::string		fname;
	std::string		lname;
	std::string		nname;
	std::string		phone;
	std::string		secret;

	public:
	bool	get_fname(void);
	bool	get_lname(void);
	bool	get_nname(void);
	bool	get_phonenbr(void);
	bool	get_secret(void);
	bool	fill_cont(void);
	void	display_cont(int ind);
	void	display_all(void);
};

class PhoneBook {
	public:
	Contact cl[8];
	int		n;

	void	rotate(void);
};

#endif
