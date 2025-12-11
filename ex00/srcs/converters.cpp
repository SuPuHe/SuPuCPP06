/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:16:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/11 12:40:31 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	convertFromChar(std::string const &literal)
{
	char c = literal[0];

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	convertFromPseudoFloat(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;

	std::string _double = literal;
	_double.pop_back();
	std::cout << "double: " << _double << std::endl;
}

void	convertFromPseudoDouble(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void	convertFromInt(std::string const &literal)
{
	long long	n;

	try{
		n = std::stoll(literal);
	}	catch (...){
		std::cout << IMPOSSIBLE_MSG << std::endl;
		return;
	}

	if (n < 0 || n > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << "" << std::endl;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;

	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;

}

void	convertFromFloat(std::string const &literal)
{
	float	f;

	try{
		f = std::stof(literal);
	}	catch (...){
		std::cout << IMPOSSIBLE_MSG << std::endl;
		return;
	}

	if (f < 0 || f > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << "" << std::endl;

	if (static_cast<int>(f) < std::numeric_limits<int>::min() || static_cast<int>(f) > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	convertFromDouble(std::string const &literal)
{
	double	d;

	try{
		d = std::stod(literal);
	}	catch (...){
		std::cout << IMPOSSIBLE_MSG << std::endl;
		return;
	}

	if (d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << "" << std::endl;

	if (static_cast<int>(d) < std::numeric_limits<int>::min() || static_cast<int>(d) > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
