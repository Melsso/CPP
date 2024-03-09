/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:47 by smallem           #+#    #+#             */
/*   Updated: 2024/01/17 16:26:00 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_HPP
# define INC_HPP

template <typename T>
T max(T &a, T &b) {
    return (a > b) ? a : b;
}

template <typename T>
T min(T &a, T &b) {
    return (a < b) ? a : b;
}

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif
