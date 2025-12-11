/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:56:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/11 12:38:02 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	ScalarConverter::convert(std::string const &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal))
		convertFromChar(literal);
	else if (isPseudoFloat(literal))
		convertFromPseudoFloat(literal);
	else if (isPseudoDouble(literal))
		convertFromPseudoDouble(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cout << IMPOSSIBLE_MSG << std::endl;
}
