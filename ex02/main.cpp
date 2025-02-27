/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:50:37 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/27 23:04:24 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ランダムに A、B、C のインスタンスを生成し、Base ポインタとして返す関数
Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

// ポインタ p が指すオブジェクトの実際の型を判定し、A、B、C のいずれかを出力する関数
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// 参照 p が指すオブジェクトの実際の型を判定し、A、B、C のいずれかを出力します。ポインタを使用せずに型を判定するために dynamic_cast を使用する関数
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}

// generate 関数を呼び出してランダムなオブジェクトを生成し、その型を identify 関数で判定して出力する関数
int main(void)
{
	srand(time(NULL));
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}
