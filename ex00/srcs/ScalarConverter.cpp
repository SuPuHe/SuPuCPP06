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

bool	isPseudoFloat(const std::string &s)
{
	return s == "inff" || s == "-inff" || s == "+inff" || s == "nanf";
}

bool	isPseudoDouble(const std::string &s)
{
	return s == "inff" || s == "-inff" || s == "+inff" || s == "nanf";
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

static bool isDouble(const std::string &s) {
	bool dot = false;

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '.') {
			if (dot) return false;
			dot = true;
		}
		else if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return false;
	}
	return dot;
}

void	printInfo(int n, float f, bool dot)
{
	std::string	after_num;
	std::string	non;
	if (dot)
		after_num = "";
	else
		after_num = ".0";
	if (isprint(n))
		non = "";
	else
		non = "Non displayable";


	std::cout << "char: " << (unsigned char)n << non << std::endl
		<< "int: " << n << std::endl
		<< "float: " << f << after_num << "f" << std::endl
		<< "double: " << f << after_num << std::endl;
}

void	printInfoChar(char c)
{
	std::cout << "char: " << c << std::endl
		<< "int: " << (unsigned int)c << std::endl
		<< "float: " << (unsigned int)c << ".0f" << std::endl
		<< "double: " << (unsigned int)c << ".0" << std::endl;
}



void	ScalarConverter::convert(std::string const &literal)
{
	int		i;
	char	c;
	float	f;
	//double	d;

	if (isChar(literal))
	{
		c = literal.at(0);
		printInfoChar(c);
		return ;
	}
	std::cout << "HERE1" << std::endl;
	if (literal.back() == 'f' )
	{
		i = std::stoi(literal);
		f = std::stof(literal);

		std::cout << f / i << std::endl;

		if (f / i != 1 && i != 0)
			printInfo(i, f, true);
		else
			printInfo(i, f, false);
		return ;
	}
	std::cout << "HERE2" << std::endl;
	if (literal.find(".") != std::string::npos)
	{
		//std::cout << "double" << std::endl;
		i = std::stoi(literal);
		f = std::stof(literal);

		if (f / i != 1 && i != 0)
			printInfo(i, f, true);
		else
			printInfo(i, f, false);
		return ;
	}
	std::cout << "HERE" << std::endl;
	try{
		i = std::stoi(literal);
	}
	catch(std::exception &e)
	{
		if (literal.find("inf") != std::string::npos || literal.find("nan") != std::string::npos)
			std::cout << "imp" << std::endl;
	}
}
