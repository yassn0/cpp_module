#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NO
};

static int ft_isprint(int c)
{
	if (c <= 31 || c >= 127)
		return (0);
	return (1);
}

static type detect_type(std::string str)
{
	bool hasDecimal = false;
	bool isFloat = false;
	size_t start = 0;

	if (str == "nan" || str == "nanf")
		return FLOAT;
	if (str == "+inf" || str == "-inf" || str == "inf")
		return DOUBLE;
	if (str == "+inff" || str == "-inff" || str == "inff")
		return FLOAT;
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9') && (ft_isprint(str[0])))
		return CHAR;

	if (str[0] == '+' || str[0] == '-')
		start = 1;
	for (size_t i = start; i < str.length(); i++)
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

static void display_int(std::string str)
{
	int data = atoi(str.c_str());

	char arg_char = static_cast<unsigned char>(data);
	if (!ft_isprint(arg_char))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char: " << arg_char << std::endl;

	std::cout << "int: " << data << std::endl;

	float arg_float = static_cast<float>(data);
	std::cout << "float: " << std::fixed << std::setprecision(1) << arg_float << "f" << std::endl;

	double arg_double = static_cast<double>(data);
	std::cout << "double: " << std::fixed << std::setprecision(1) << arg_double << std::endl;
}

static void display_char(std::string str)
{
	(void)str;
}

static void display_float(std::string str)
{
	float data = atof(str.c_str());

	char arg_char = static_cast<unsigned char>(data);
	if (!ft_isprint(arg_char))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char: " << arg_char << std::endl;
		
	int arg_int = static_cast<int>(data);
	std::cout << "int: " << arg_int << std::endl;
	
	std::cout << "float: " << data << "f" << std::endl;
	
	double arg_double = static_cast<double>(data);
	std::cout << "double: " << arg_double << std::endl;
		
}

static void display_double(std::string str)
{
	
}

void ScalarConverter::convert(std::string str)
{
	type t = detect_type(str);
	if (t == NO)
	{
		std::cout << "Argument not valid" << std::endl;
		return;
	}
	if (t == INT)
		display_int(str);
	else if (t == CHAR)
		display_char(str);
	else if (t == FLOAT)
		display_float(str);
	else if (t == DOUBLE)
		display_double(str)
}

//pas oublier les cas particulier pour float et double, et gestion d'erreur pour atoi pour nombre trop grands, pareil pour atof