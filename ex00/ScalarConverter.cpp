/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:07:19 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/20 22:08:07 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

static bool isChar(const std::string &literal);
static bool isInt(const std::string &literal);
static bool isFloat(const std::string &literal);
static bool isDouble(const std::string &literal);

void ScalarConverter::convert(const std::string &literal) {
    // Detect type and print conversion results
    char c;
    int i;
    float f;
    double d;

    try {
        if (isChar(literal)) {
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        } else if (isInt(literal)) {
            i = std::atoi(literal.c_str());
            c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 'N';
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        } else if (isFloat(literal)) {
            f = std::atof(literal.c_str());
            i = static_cast<int>(f);
            c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 'N';
            d = static_cast<double>(f);
        } else if (isDouble(literal)) {
            d = std::strtod(literal.c_str(), NULL);
            i = static_cast<int>(d);
            c = (i >= 32 && i <= 126) ? static_cast<char>(i) : 'N';
            f = static_cast<float>(d);
        } else {
            throw std::invalid_argument("Invalid literal");
        }
    } catch (const std::exception &e) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    // Output results
    std::cout << "char: " << ((c == 'N') ? "Non displayable" : std::string(1, c)) << "\n";
    std::cout << "int: " << i << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}
