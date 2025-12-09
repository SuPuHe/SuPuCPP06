/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:55:04 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 16:51:40 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data
{
	int			number;
	std::string	str;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);
		Serializer &operator=(Serializer const &copy);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);

		static Data*		deserialize(uintptr_t raw);
};
