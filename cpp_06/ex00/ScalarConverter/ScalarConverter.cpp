#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NO
};

static type detect_type(std::string str)
{
	bool hasDecimal = false;
	bool isFloat = false;
	int start = 0;

	if (str == "nan" || str == "nanf")
		return FLOAT;
	if (str == "+inf" || str == "-inf" || str == "inf")
		return DOUBLE;
	if (str == "+inff" || str == "-inff" || str == "inff")
		return FLOAT;
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9') && (str[0] >= 32 && str[0] <= 126))
		return CHAR;

	if (str[0] == '+' || str[0] == '-')
		start = 1;
	for (int i = start; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDecimal)
				return NO;
			hasDecimal = true;
		}
		else if (str[i] == 'f' && i == str.length() - 1)
			isFloat = true;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return NO;
	}
	if (start >= str.length())
		return NO;
	if (isFloat)
		return FLOAT;
	else if (hasDecimal)
		return DOUBLE;
	else
		return INT;
}

void ScalarConverter::convert(std::string str)
{
	type a = detect_type(str);
	if (a == NO)
	{
		std::cout << "Argument not valid" << std::endl;
		return ;
	}
}
