/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:07:19 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/26 20:37:34 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// デフォルトコンストラクタ（プライベート）
ScalarConverter::ScalarConverter(void)
{ }

// コピーコンストラクタ（プライベート）
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

// デストラクタ（プライベート）
ScalarConverter::~ScalarConverter(void)
{ }

// 代入演算子（プライベート）
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

// 文字列をさまざまなスカラー型に変換する静的メソッド
void    ScalarConverter::convert(const std::string& str)
{
    size_t  len = str.length();
    e_type  type = whichType(str, len);
    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl; // 入力文字列の型を判定する
            break;
        case SPECIAL:
            printSpecial(str);
            break;
        case CHAR:
            convertChar(str, len);
            break;
        case INT:
            convertInt(str);
            break;
        case FLOAT:
            convertFloat(str);
            break;
        case DOUBLE:
            convertDouble(str);
            break;
    }
}
