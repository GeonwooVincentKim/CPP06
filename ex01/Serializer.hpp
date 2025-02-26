/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:38:08 by geonwkim          #+#    #+#             */
/*   Updated: 2025/02/26 22:38:08 by geonwkim         ###   ########.fr       */
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
		Serializer(void);
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
