/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smallem <smallem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:41:15 by smallem           #+#    #+#             */
/*   Updated: 2024/03/09 15:54:12 by smallem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int is_valid(const std::string &str) {
    size_t  i;
    int     p_count = 0;
    int     f_count = 0;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    else if (str[i] == '.' || str[i] == 'f')
        return 0;
    for (size_t j = i; j < str.length(); ++j) {
        if (str[j] == '.')
            p_count++;
        else if (str[j] == 'f')
            f_count++;
        else if (!std::isdigit(str[j]))
            return 0;
    }
    if (p_count > 1 || f_count > 1)
        return 0;
    if (p_count == 1 && str[str.length() - 1] == '.')
        return 0;
    if (f_count == 1 && str[str.length() - 1] != 'f')
        return 0;
    return 1;
}

void    print(bool c_flag, bool i_flag, bool f_flag, bool d_flag, bool inf_flag,
    const std::string &str) {
    int     n;
    float   f;
    double  d;
    char    *res;

    if (c_flag) {
        std::cout << "Char  : " << str[0] << std::endl;
        std::cout << "Int   : " << static_cast<int>(str[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "Float : " << static_cast<float>(str[0]) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "Double: " << static_cast<double>(str[0]) << std::endl; 
    }
    else if (i_flag) {
        n = std::atoi(str.c_str());
        if (n >= 32 && n <= 127)
            std::cout << "Char  : " << static_cast<char>(n) << std::endl;
        else
            std::cout << "Char  : Non Displayable" << std::endl;
        std::cout << "Int   : " << n << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "Float : " << static_cast<float>(n) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "Double: " << static_cast<double>(n) << std::endl; 
    }
    else if (f_flag) {
        // f = std::stof(str);
        std::string tmp = str.substr(0, str.length() - 1);
        f = std::strtof(tmp.c_str(), &res);
        if (*res != '\0')
            throw std::invalid_argument("Invalid input for stof");
        if (f >= 32 && f <= 127)
            std::cout << "Char  : " << static_cast<char>(f) << std::endl;
        else if (inf_flag)
            std::cout << "Char  : Impossible" << std::endl;
        else
            std::cout << "Char  : Non Displayable" << std::endl;
        if (inf_flag)
            std::cout << "Int  : Impossible" << std::endl;
        else
            std::cout << "Int   : " << static_cast<int>(f) << std::endl;
                
        std::cout << std::fixed << "Float : " << f << "f" << std::endl;
        std::cout << std::fixed << "Double: " << static_cast<double>(f) << std::endl;
    }
    else if (d_flag) {
        // d = std::stod(str);
        d = std::strtod(str.c_str(), &res);
        if (*res != '\0')
            throw std::invalid_argument("Invalid input for stod");
        if (d >= 32 && d <= 127)
            std::cout << "Char  : " << static_cast<char>(d) << std::endl;
        else if (inf_flag)
            std::cout << "Char  : Impossible" << std::endl;
        else
            std::cout << "Char  : Non Displayable" << std::endl;
        if (inf_flag)
            std::cout << "Int  : Impossible" << std::endl;
        else
            std::cout << "Int   : " << static_cast<int>(d) << std::endl;
        
        std::cout << std::fixed << "Float : " << static_cast<float>(d) << "f" << std::endl;
        std::cout << std::fixed << "Double: " << d << std::endl;
    }
}

void    ScalarConverter::convert(const std::string &str) {
    bool    d_flag = false;
    bool    f_flag = false;
    bool    c_flag = false;
    bool    i_flag = false;
    bool    inf_flag = false;
    size_t  pos;

    if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan") {
        d_flag = true;
        inf_flag = true;
    }
    else if (str == "inff" || str == "nanf" || str == "+inff" || str == "-inff") {
        f_flag = true;
        inf_flag = true;
    }
    else if (str.length() == 1) {
        if (std::isdigit(str[0]))
            i_flag = true;
        else
            c_flag = true;
    }
    else {
        if (!is_valid(str)) {
            std::cout << "Error: Invalid input!" << std::endl;
            return ;
        }
        pos = str.find("f");
        if (pos != std::string::npos)
            f_flag = true;
        pos = str.find(".");
        if (pos != std::string::npos && !f_flag)
            d_flag = true;
        if (!f_flag && !d_flag)
            i_flag = true;
    }
    print(c_flag, i_flag, f_flag, d_flag, inf_flag, str);
}

