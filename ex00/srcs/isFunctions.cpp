/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFunctions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:14 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 12:16:03 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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

bool	isInt(const std::string &s)
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

bool	isFloat(const std::string &s)
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

bool	isDouble(const std::string &s)
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
