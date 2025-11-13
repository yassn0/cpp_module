#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _map_data(other._map_data)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_map_data = other._map_data;
	}
	return *this;
}

static std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return str.substr(first, last - first + 1);
}

static int split(std::string &line, char delim, std::string &date, std::string &val)
{
	size_t pos = line.find(delim);
	if (pos == std::string::npos)
	{
		date = line.substr(0, line.size());
		val = "-1";
		return 1;
	}
	date = trim(line.substr(0, pos));
	val = trim(line.substr(pos + 1));
	return 1;
}

static int verif_date(const std::string &date)
{
	if (date.size() != 10)
		return 0;
	if (date[4] != '-' || date[7] != '-')
		return 0;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return 0;
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return 0;
	if (day < 1 || day > 31)
		return 0;

	// Check days per month
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Check for leap year
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		days_in_month[1] = 29;

	if (day > days_in_month[month - 1])
		return 0;

	return 1;
}

int BitcoinExchange::getData(char *av)
{
	std::ifstream fd;
	std::string line, date, val;

	fd.open(av);
	if (fd.fail())
	{
		std::cerr << "Error: could not open file." << std::endl;
		fd.close();
		return 0;
	}
	std::getline(fd, line);
	if (line.compare("date | value"))
	{
		fd.close();
		std::cerr << "Error: need 'date | value' at start of input file" << std::endl;
		return 0;
	}
	while (std::getline(fd, line))
	{
		split(line, '|', date, val);
		_map_data.insert(std::pair<std::string, double>(date, atof(val.c_str())));
	}
	fd.close();

	return 1;
}

int BitcoinExchange::displayData()
{
	std::ifstream db("./db/data.csv");
	std::string line, date, val;
	std::multimap<std::string, double> db_map;
	float multiplicator;

	if (db.fail())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return 0;
	}

	std::getline(db, line);
	while (std::getline(db, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		date = line.substr(0, pos);
		val = line.substr(pos + 1);
		db_map.insert(std::pair<std::string, double>(trim(date), atof(val.c_str())));
	}
	db.close();

	for (std::multimap<std::string, double>::iterator it = _map_data.begin(); it != _map_data.end(); ++it)
	{
		const std::string &input_date = it->first;
		double input_value = it->second;

		if (!verif_date(input_date))
			std::cout << "Error: bad input => " << input_date << std::endl;
		else if (input_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (input_value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::multimap<std::string, double>::iterator it_db = db_map.lower_bound(input_date);
			if (it_db == db_map.begin() && it_db->first != input_date)
			{
				std::cout << "Error: no data available before this date => " << input_date << std::endl;
				continue;
			}
			if (it_db == db_map.end() || it_db->first != input_date)
				--it_db;
			multiplicator = it_db->second;
			std::cout << input_date << " => ";
			if (input_value == static_cast<int>(input_value))
				std::cout << static_cast<int>(input_value);
			else
				std::cout << std::fixed << std::setprecision(1) << input_value;
			std::cout << " = " << std::fixed << std::setprecision(2) << (input_value * multiplicator) << std::endl;
		}
	}
	return 1;
}