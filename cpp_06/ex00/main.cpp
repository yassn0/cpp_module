#include <iostream>
#include <string>
#include "ScalarConverter/ScalarConverter.hpp"



int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "One argument only is required !" << std::endl;
		return 1;
	}
	std::string arg = static_cast<std::string>(av[1]);

	ScalarConverter::convert(arg);
}