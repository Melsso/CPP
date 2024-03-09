/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:59:56 by smallem           #+#    #+#             */
/*   Updated: 2024/01/18 18:00:29 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <exception>
# include <deque>
# include <time.h>


class Span {
	private:
		unsigned int 	n;
		std::deque<int> list;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const Span &cp);
		Span &operator=(const Span &member);
		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();
		std::deque<int> getList() const;
		void generateNumbers();

		class TooManyNumbers : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbers : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
