/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:16:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 12:17:30 by omizin           ###   ########.fr       */
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
	std::cout << "int: " << (int)c << std::endl;
	std::cout << "float: " << (float)c << "f" << std::endl;
	std::cout << "double: " << (double)c << std::endl;
	exit(0);
}

void	convertFromPseudoFloat(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;

	std::string _double = literal;
	_double.pop_back();
	std::cout << "double: " << _double << std::endl;
	exit(0);
}

void	convertFromPseudoDouble(std::string const &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << "f" << std::endl;
	std::cout << "double: " << literal << std::endl;
	exit(0);
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
	else if (!isprint((char)n))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << (char)n << "" << std::endl;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;

	std::cout << "float: " << (float)n << "f" << std::endl;
	std::cout << "double: " << (double)n << std::endl;

	exit(0);
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
	else if (!isprint((char)f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << (char)f << "" << std::endl;

	if ((int)f < std::numeric_limits<int>::min() || (int)f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int)f << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << (double)f << std::endl;
	exit(0);
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
	else if (!isprint((char)d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << (char)d << "" << std::endl;

	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int)d << std::endl;

	std::cout << "float: " << d << "f" << std::endl;
	std::cout << "double: " << (double)d << std::endl;
	exit(0);
}
