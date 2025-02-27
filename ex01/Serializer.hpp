/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:38:08 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/27 22:49:31 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include "Data.hpp"
# include <iostream>

class Serializer
{
	private:
		Serializer(void); // プライベートコンストラクタ
		Serializer(Serializer const &other); // コピーコンストラクタ
		Serializer &operator=(Serializer const &other); // 代入演算子のオーバーロード
		~Serializer(void); // デストラクタ

	public:
		static uintptr_t serialize(Data* ptr); // ポインタをuintptr_tに変換する静的メソッド
		static Data* deserialize(uintptr_t raw); // uintptr_tをポインタに変換する静的メソッド
};

#endif
