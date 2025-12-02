/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:47:09 by opopov            #+#    #+#             */
/*   Updated: 2025/11/29 14:33:37 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static std::string ValueCheck(const std::string &str)
{
	char *end;
	// Check for special float literals first
	if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff")
		return ("float");
	
	// Check for special double literals
	if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf")
		return ("double");

	// Check for char
	if (str.length() == 1 && !isdigit(str[0]))
		return ("char");

	// Check for float (ends with 'f')
	if (str.length() > 0 && str[str.length() - 1] == 'f')
	{
		std::strtof(str.c_str(), &end);
		if (*end == 'f' && *(end + 1) == '\0')
			return ("float");
	}

	// Check for int
	std::strtol(str.c_str(), &end, 10);
	if (*end == '\0')
		return ("int");

	// Check for double
	std::strtold(str.c_str(), &end);
	if (*end == '\0')
		return ("double");
	return ("string");
}

void ScalarConverter::convert(const std::string &str)
{
	DoubleHandler d;
	CharHandler ch;
	IntHandler i;
	FloatHandler f;
	std::string res = ValueCheck(str);
	ch.HandleChar(str, res);
	i.HandleInt(str, res);
	f.HandleFloat(str, res);
	d.HandleDouble(str, res);
}
