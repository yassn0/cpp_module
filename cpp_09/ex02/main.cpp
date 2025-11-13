#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>
#include <limits.h>
#include <set>

bool isValidNumber(const std::string &str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	char *endptr;
	long num = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || num < 0 || num > INT_MAX)
		return false;
	return true;
}

bool noDoublon(const std::vector<int> &vec)
{
	std::set<int> seen;
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (seen.find(vec[i]) != seen.end())
			return false;
		seen.insert(vec[i]);
	}
	return true;
}

double getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void printSequence(const std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i + 1 < vec.size() && i + 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::vector<int> input_vec;
	std::deque<int> input_deq;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		if (!isValidNumber(arg))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		int num = std::atoi(av[i]);
		input_vec.push_back(num);
		input_deq.push_back(num);
	}

	if (!noDoublon(input_vec))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	printSequence(input_vec);

	double start_vec = getTime();
	PmergeMe sorter;
	sorter.sortVector(input_vec);
	double end_vec = getTime();
	double time_vec = end_vec - start_vec;

	double start_deq = getTime();
	sorter.sortDeque(input_deq);
	double end_deq = getTime();
	double time_deq = end_deq - start_deq;

	std::cout << "After:  ";
	printSequence(input_vec);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << input_vec.size()
			  << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << input_deq.size()
			  << " elements with std::deque  : " << time_deq << " us" << std::endl;
	return 0;
}
