/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:11:38 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 12:18:26 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <limits>

#include "ScalarConverter.hpp"

#define IMPOSSIBLE_MSG "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible"

bool	isPseudoFloat(const std::string &s);
bool	isPseudoDouble(const std::string &s);
bool	isChar(const std::string &s);
bool	isInt(const std::string &s);
bool	isFloat(const std::string &s);
bool	isDouble(const std::string &s);

void	convertFromChar(std::string const &literal);
void	convertFromPseudoFloat(std::string const &literal);
void	convertFromPseudoDouble(std::string const &literal);
void	convertFromInt(std::string const &literal);
void	convertFromFloat(std::string const &literal);
void	convertFromDouble(std::string const &literal);

