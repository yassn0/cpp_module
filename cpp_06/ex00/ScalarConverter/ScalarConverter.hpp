#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string& str);
	
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
};

#endif