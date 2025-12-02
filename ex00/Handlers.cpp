/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:21:16 by opopov            #+#    #+#             */
/*   Updated: 2025/11/29 14:30:31 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ------------------------------Utils!-----------------------------

bool CheckForLimits(const long double &ld, const std::string &res)
{
	if (res == "int" &&
		(ld < std::numeric_limits<int>::min()
		|| ld > std::numeric_limits<int>::max()))
		return (false);
	else if (res == "float" &&
		(ld < -std::numeric_limits<float>::max()
		|| ld > std::numeric_limits<float>::max()))
		return (false);
	else if (res == "double" &&
		(ld < -std::numeric_limits<double>::max()
		|| ld > std::numeric_limits<double>::max()))
		return (false);
	return (true);
}

// ------------------------------Char Handler!-----------------------------

void CharHandler::PrintChar(const char &val, const int &i)
{
	switch (i)
	{
		case ERROR:
			std::cout << "char: Error" << std::endl;
			return ;
		case NDISPLAYABLE:
			std::cout << "char: Non displayable" << std::endl;
			return ;
		case VAL:
			std::cout << "char: " << val << std::endl;
			return ;
		case EXCEPTION:
			std::cout << "char: " << val << std::endl;
			return ;
	}
}

int CharHandler::CheckChar(const std::string &str, const std::string &res)
{
	char *end;
	long double ld;
	if (str == "nan" || str == "nanf" ||
		str == "+inf" || str == "+inff" ||
		str == "-inf" || str == "-inff")
		return (ERROR);
	if (res == "char")
		return (EXCEPTION);
	else if (res == "int" || res == "float" || res == "double")
	{
		ld = std::strtold(str.c_str(), &end);
		if (ld < 0 || ld > 127)
			return (ERROR);
		else if (ld < 32 || ld == 127)
			return (NDISPLAYABLE);
		if (CheckForLimits(ld, res) == false)
			return (ERROR);
	}
	else
		return (ERROR);
	return (VAL);
}

void CharHandler::HandleChar(const std::string &str, const std::string &res)
{
	int check = CheckChar(str, res);
	if (check != VAL)
	{
		PrintChar(str[0], check);
		return ;
	}
	char *end;
	long l = std::strtol(str.c_str(), &end, 10);
	PrintChar((char)l, check);
}

// ------------------------------Int Handler!-----------------------------

void IntHandler::PrintInt(const int &val, const int &i)
{
	switch (i)
	{
		case ERROR:
			std::cout << "int: Error" << std::endl;
			return ;
		case VAL:
			std::cout << "int: " << val << std::endl;
			return ;
	}
}

int IntHandler::CheckInt(const std::string &str, const std::string &res)
{
	char *end;
	long double ld;
	if (str == "nan" || str == "nanf" ||
		str == "+inf" || str == "+inff" ||
		str == "-inf" || str == "-inff")
		return (ERROR);
	if (res == "char")
		return (VAL);
	else if (res == "int" || res == "float" || res == "double")
	{
		ld = std::strtold(str.c_str(), &end);
		if (CheckForLimits(ld, res) == false)
			return (ERROR);
	}
	else
		return (ERROR);
	return (VAL);
}

void IntHandler::HandleInt(const std::string &str, const std::string &res)
{
	int check = CheckInt(str, res);
	if (check != VAL)
	{
		PrintInt(str[0], check);
		return ;
	}
	char *end;
	long l;
	if (res == "char")
		l = static_cast<int>(str[0]);
	else
		l = std::strtol(str.c_str(), &end, 10);
	PrintInt(l, check);
}

// ------------------------------Float Handler!-----------------------------

void FloatHandler::PrintFloat(const float &val, const int &i)
{
	switch (i)
	{
		case ERROR:
			std::cout << "float: Error" << std::endl;
			return ;
		case VAL:
			std::cout << "float: " << val;
			if (val == static_cast<int>(val))
				std::cout << ".0";
			std::cout << "f" << std::endl;
			return ;
		case NAN:
			std::cout << "float: nanf" << std::endl;
			return ;
	}
}

int FloatHandler::CheckFloat(const std::string &str, const std::string &res)
{
	char *end;
	long double ld;
	if (str == "nan" || str == "nanf")
		return (NAN);
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (VAL);
	if (res == "char")
		return (VAL);
	else if (res == "int" || res == "float" || res == "double")
	{
		ld = std::strtold(str.c_str(), &end);
		if (CheckForLimits(ld, res) == false)
			return (ERROR);
	}
	else
		return (ERROR);
	return (VAL);
}

void FloatHandler::HandleFloat(const std::string &str, const std::string &res)
{
	int check = CheckFloat(str, res);
	if (check != VAL)
	{
		PrintFloat(str[0], check);
		return ;
	}
	char *end;
	float f;
	if (res == "char")
		f = static_cast<float>(str[0]);
	else
		f = std::strtof(str.c_str(), &end);
	PrintFloat(f, check);
}

// ------------------------------Double Handler!-----------------------------

void DoubleHandler::PrintDouble(const double &val, const int &i)
{
	switch (i)
	{
		case ERROR:
			std::cout << "double: Error" << std::endl;
			return ;
		case VAL:
			std::cout << "double: " << val;
			if (val == static_cast<int>(val))
				std::cout << ".0";
			std::cout << std::endl;
			return ;
		case NAN:
			std::cout << "double: nan" << std::endl;
			return ;
	}
}

int DoubleHandler::CheckDouble(const std::string &str, const std::string &res)
{
	char *end;
	long double ld;
	if (str == "nan" || str == "nanf")
		return (NAN);
	if (str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (VAL);
	if (res == "char")
		return (VAL);
	else if (res == "int" || res == "float" || res == "double")
	{
		ld = std::strtold(str.c_str(), &end);
		if (CheckForLimits(ld, res) == false)
			return (ERROR);
	}
	else
		return (ERROR);
	return (VAL);
}

void DoubleHandler::HandleDouble(const std::string &str, const std::string &res)
{
	int check = CheckDouble(str, res);
	if (check != VAL)
	{
		PrintDouble(str[0], check);
		return ;
	}
	char *end;
	long double ld;
	if (res == "char")
		ld = static_cast<double>(str[0]);
	else
		ld = std::strtold(str.c_str(), &end);
	PrintDouble(ld, check);
}

// ------------------------------Initialization!-----------------------------

Handler::Handler()
{
}

Handler::~Handler()
{
}

IntHandler::IntHandler()
{
}

IntHandler::IntHandler(const IntHandler &other)
{
	(void)other;
}

IntHandler &IntHandler::operator=(const IntHandler &other)
{
	(void)other;
	return (*this);
}

IntHandler::~IntHandler()
{
}

FloatHandler::FloatHandler()
{
}

FloatHandler::FloatHandler(const FloatHandler &other)
{
	(void)other;
}

FloatHandler &FloatHandler::operator=(const FloatHandler &other)
{
	(void)other;
	return (*this);
}

FloatHandler::~FloatHandler()
{
}

DoubleHandler::DoubleHandler()
{
}

DoubleHandler::DoubleHandler(const DoubleHandler &other)
{
	(void)other;
}

DoubleHandler &DoubleHandler::operator=(const DoubleHandler &other)
{
	(void)other;
	return (*this);
}

DoubleHandler::~DoubleHandler()
{
}

CharHandler::CharHandler()
{
}

CharHandler::CharHandler(const CharHandler &ch)
{
	(void)ch;
}

CharHandler &CharHandler::operator=(const CharHandler &ch)
{
	(void)ch;
	return (*this);
}

CharHandler::~CharHandler()
{
}
