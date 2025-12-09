/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:56:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 12:16:56 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	ScalarConverter::convert(std::string const &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal))
		convertFromChar(literal);
	if (isPseudoFloat(literal))
		convertFromPseudoFloat(literal);
	if (isPseudoDouble(literal))
		convertFromPseudoDouble(literal);
	if (isInt(literal))
		convertFromInt(literal);
	if (isFloat(literal))
		convertFromFloat(literal);
	if (isDouble(literal))
		convertFromDouble(literal);
	std::cout << IMPOSSIBLE_MSG << std::endl;
}
