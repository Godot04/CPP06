/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:47:20 by opopov            #+#    #+#             */
/*   Updated: 2025/11/29 16:53:04 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <limits>

class Handler;
class CharHandler;
class IntHandler;
class FloatHandler;
class DoubleHandler;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void convert(const std::string &str);
};

class Handler
{
	protected:
		enum values
		{
			VAL,
			ERROR,
			NDISPLAYABLE,
			EXCEPTION,
			NAN
		};
	public:
		Handler();
		~Handler();
};

class CharHandler : Handler
{
	private:
		void PrintChar(const char &c, const int &i);
		int CheckChar(const std::string &str, const std::string &res);
	public:
		CharHandler();
		CharHandler(const CharHandler &ch);
		CharHandler &operator=(const CharHandler &ch);
		~CharHandler();
		void HandleChar(const std::string &str, const std::string &res);
};

class IntHandler : Handler
{
	private:
		void PrintInt(const int &c, const int &i);
		int CheckInt(const std::string &str, const std::string &res);
	public:
		IntHandler();
		IntHandler(const IntHandler &other);
		IntHandler &operator=(const IntHandler &other);
		~IntHandler();
		void HandleInt(const std::string &str, const std::string &res);
};

class FloatHandler : Handler
{
	private:
		void PrintFloat(const float &c, const int &i);
		int CheckFloat(const std::string &str, const std::string &res);
	public:
		FloatHandler();
		FloatHandler(const FloatHandler &other);
		FloatHandler &operator=(const FloatHandler &other);
		~FloatHandler();
		void HandleFloat(const std::string &str, const std::string &res);
};

class DoubleHandler : Handler
{
	private:
		void PrintDouble(const double &c, const int &i);
		int CheckDouble(const std::string &str, const std::string &res);
	public:
		DoubleHandler();
		DoubleHandler(const DoubleHandler &other);
		DoubleHandler &operator=(const DoubleHandler &other);
		~DoubleHandler();
		void HandleDouble(const std::string &str, const std::string &res);
};

bool CheckForLimits(const long double &ld, const std::string &res);

#endif
