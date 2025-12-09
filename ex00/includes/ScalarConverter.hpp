/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:56:43 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 12:15:08 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(ScalarConverter const &copy);
		~ScalarConverter();
	public:
		static void	convert(std::string const &literal);
};
