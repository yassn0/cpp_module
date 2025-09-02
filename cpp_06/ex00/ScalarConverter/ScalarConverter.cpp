#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NO
};

static bool isSpecialFloat(const std::string &str)
{
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" ||
		  str == "inf" || str == "+inff" || str == "-inff" || str == "inff");
}

static type detect_type(const std::string &str)
{
	if (str.empty())
		return NO;
	if (isSpecialFloat(str))
	{
		if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
			return FLOAT;
		return DOUBLE;
	}

	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
		return CHAR;

	size_t start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;

	if (start >= str.length())
		return NO;

	bool hasDecimal = false;
	bool isFloat = false;

	for (size_t i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDecimal)
				return NO;
			hasDecimal = true;
		}
		else if (str[i] == 'f' && i == str.length() - 1 && i > start)
			isFloat = true;
		else if (!std::isdigit(str[i]))
			return NO;
	}

	if (isFloat)
		return FLOAT;
	else if (hasDecimal)
		return DOUBLE;
	else
		return INT;
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (value != value || value == std::numeric_limits<double>::infinity() ||
	    value == -std::numeric_limits<double>::infinity())
		std::cout << "impossible";
	else if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (value < 32 || value == 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (value != value || value == std::numeric_limits<double>::infinity() ||
	    value == -std::numeric_limits<double>::infinity())
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (value != value)
		std::cout << "nanf";
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inff";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inff";
	else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	}
	std::cout << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (value != value)
		std::cout << "nan";
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inf";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf";
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	type detectedType = detect_type(str);
	double value = 0;

	if (detectedType == NO)
	{
		std::cout << "Enter a valid argument" << std::endl;
		return ;
	}

	if (detectedType == CHAR)
		value = static_cast<double>(str[0]);
	else if (detectedType == INT || detectedType == FLOAT || detectedType == DOUBLE)
	{
		if (isSpecialFloat(str))
		{
			if (str == "nan" || str == "nanf")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
				value = std::numeric_limits<double>::infinity();
			else if (str == "-inf" || str == "-inff")
				value = -std::numeric_limits<double>::infinity();
		}
		else
			value = std::atof(str.c_str());
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
