#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);

	int getData(char *av);
	int displayData(void);

private:
	std::multimap<std::string, double> _map_data;
};
