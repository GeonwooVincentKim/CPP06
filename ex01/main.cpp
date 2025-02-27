/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:37:01 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/27 22:49:59 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->age = 42;
	data->sername = "Meier";

	uintptr_t raw = Serializer::serialize(data); // Dataオブジェクトのアドレスをシリアライズ
	Data *serialized = Serializer::deserialize(raw); // シリアライズされた値をデシリアライズ

	// デシリアライズされたオブジェクトのデータメンバーを出力
	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;
	std::cout << serialized->sername << std::endl;

	delete data;
	return (0);
}
