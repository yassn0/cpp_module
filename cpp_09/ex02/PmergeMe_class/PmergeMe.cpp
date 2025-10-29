#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vector_time(0.0), _deque_time(0.0)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _deque(copy._deque)
{
	std::cout << "PmergeMe Copy Constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	std::cout << "PmergeMe operator= called" << std::endl;
	return *this;
}

static void printInt(int x)
{
	std::cout << x << " ";
}

bool PmergeMe::check(int ac, char **av)
{
	double n = -1;
	
	_vector.reserve(ac);
	for (int i = 1; i < ac; i++)
	{
		if (!strcmp(av[i], "0"))
		{
			_vector.push_back(0);
			_deque.push_back(0);
		}
		else
		{
			if ((n = std::atof(av[i])) == 0.0 || (n < 0) || (n > INT_MAX))
				return false;
			std::vector<int>::iterator it = std::find(_vector.begin(), _vector.end(), n);
			if (it != _vector.end())
			{
				std::cerr << "Duplicate ";
				return false;
			}
			_vector.push_back(static_cast<int>(n));
			_deque.push_back(static_cast<int>(n));
		}
	}
	
	std::cout << "Before:\t";
	for_each(_vector.begin(), _vector.end(), printInt);
	std::cout << std::endl;
	
	return true;
}

double PmergeMe::getTimeDiff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) * 1000000.0) + (end.tv_usec - start.tv_usec);
}

void PmergeMe::printResults()
{
	std::cout << "After:\t";
	for_each(_vector.begin(), _vector.end(), printInt);
	std::cout << std::endl;

	std::cout << "Time to process " << _vector.size() << " elements with std::vector : " << _vector_time << " us" << std::endl;
	std::cout << "Time to process " << _deque.size() << " elements with std::deque : " << _deque_time << " us" << std::endl;
}
