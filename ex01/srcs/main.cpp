/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:54:59 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 16:51:46 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data d;
	uintptr_t raw = Serializer::serialize(&d);
	Data* ptr = Serializer::deserialize(raw);

	if (ptr == &d)
		std::cout << "OK" << std::endl;
}
