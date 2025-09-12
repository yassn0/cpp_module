#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	BitcoinExchange btc;
	
	if (ac != 2)
	{
		std::cout << "Error: Two argument needed" << std::endl;
		return 1;
	}
	if (!btc.getData(av[1]))
		return (1);
	if (!btc.displayData())
		return (1);
	
}