/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:56:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/08 17:56:34 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define IMPOSSIBLE_MSG "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"

bool	isPseudoFloat(const std::string &s)
{
	return s == "inff" || s == "-inff" || s == "+inff" || s == "nanf";
}

bool	isPseudoDouble(const std::string &s)
{
	return s == "inf" || s == "-inf" || s == "+inf" || s == "nan";
}

bool	isChar(const std::string &s)
{
	return s.length() == 1 && !isdigit(s[0]);
}

static bool isInt(const std::string &s)
{
	int	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;

	if (i == (int)s.length())
		return false;

	for (; i < (int)s.length(); i++)
		if (!isdigit(s[i]))
			return false;

	return true;
}

static bool isFloat(const std::string &s)
{
	bool	dot = false;

	if (s.back() != 'f')
		return false;

	int	len = s.length();
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] == '.') {
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return false;
	}
	return dot;
}

static bool isDouble(const std::string &s)
{
	bool dot = false;

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '.') {
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return false;
	}
	return dot;
}


void	ScalarConverter::convert(std::string const &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal))
	{
		char c = literal[0];

		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << (int)c << std::endl;
		std::cout << "float: " << (float)c << "f" << std::endl;
		std::cout << "double: " << (double)c << std::endl;
		return ;
	}
	if (isPseudoFloat(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;

		std::string _double = literal;
		_double.pop_back();
		std::cout << "double: " << _double << std::endl;
		return ;
	}
	if (isPseudoDouble(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	if (isInt(literal))
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

		return ;
	}
	if (isFloat(literal))
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

		if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << (int)f << std::endl;

		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << (double)f << std::endl;
		return ;
	}
	if (isDouble(literal))
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
		return ;
	}
	std::cout << IMPOSSIBLE_MSG << std::endl;
}
