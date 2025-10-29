#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Span Constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}

Span::Span(const Span &copy) : _tab(copy._tab), _N(copy._N)
{
	std::cout << "Span Copy Constructor called" << std::endl;
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		_N = obj._N;
		_tab = obj._tab;
	}
	std::cout << "Span operator= called" << std::endl;
	return *this;
}

void Span::addNumber(int nb)
{
	if (_tab.size() >= _N)
		throw WrongIndex();
	_tab.push_back(nb);
}

int Span::shortestSpan(void)
{
	if (_tab.size() < 2)
		throw WrongIndex();
	std::vector<int> copy = _tab;
	std::sort(copy.begin(), copy.end());
	int shortest = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size(); i++)
	{
		int distance = copy[i] - copy[i - 1];
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

int Span::longestSpan(void)
{
	if (_tab.size() < 2)
		throw WrongIndex();
	int max = *std::max_element(_tab.begin(), _tab.end());
	int min = *std::min_element(_tab.begin(), _tab.end());
	return max - min;
}

void	Span::addLotRandomNumber(int i)
{
	std::srand(std::time(0));
	
	for (int j = 0; j < i; j++)
	{
		addNumber(std::rand() % 100);
	}
}
