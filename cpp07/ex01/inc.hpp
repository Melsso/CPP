/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:28:53 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 16:43:32 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_HPP
# define INC_HPP

template <typename T, typename Func>
void	iter(T *arr, size_t size, Func f) {
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

template <typename T>
void	print_value(const T &tmp) {
	std::cout << tmp << " ";
}

#endif
