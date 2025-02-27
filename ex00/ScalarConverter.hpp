/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:07:19 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/22 20:30:00 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>

// 文字列を倍精度浮動小数点型に変換して出力する関数
# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

// 文字列を倍精度浮動小数点型に変換して出力する関数
enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

// 文字列を倍精度浮動小数点型に変換して出力する関数
class	ScalarConverter
{
	private:
		ScalarConverter(void); // プライベートコンストラクタ
		ScalarConverter(ScalarConverter const &src); // コピーコンストラクタ
		~ScalarConverter(void); // デストラクタ
		ScalarConverter	&operator=(ScalarConverter const &rhs); // 代入演算子のオーバーロード
	public:
		static void	convert(const std::string& str); // 文字列をさまざまなスカラー型に変換して出力する関数
};

// 関数の宣言
e_type	whichType(const std::string& str, size_t& len);
void	printSpecial(const std::string& str);
void	convertChar(const std::string& str, size_t& len);
void	convertInt(const std::string& str);
void	convertFloat(const std::string& str);
void	convertDouble(const std::string& str);

#endif
