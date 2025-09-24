#include <iostream>
#include "RPN.hpp"
#include <ctype.h>
#include <stack>
#include <cstdlib>

RPN::RPN(std::string input) : _input(input)
{
	std::cout << _input << std::endl;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &copy) : _input(copy._input)
{
	std::cout << "RPN Copy Constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_input = other._input;
	}
	std::cout << "RPN operator= called" << std::endl;
	return *this;
}

static bool is_operator(char i)
{
	if (i != '*' && i != '/' && i != '-' && i != '+')
		return false;
	return true;
}

static int do_operation(int n1, int n2, char operat)
{
	if (operat == '*')
		return n1 * n2;
	else if (operat == '-')
		return n1 - n2;
	else if (operat == '+')
		return n1 + n2;
	else
		return n1 / n2;
}

static bool verif_input(std::string input)
{
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && !is_operator(input[i]) && input[i] != ' ')
			return false;
		if (input[i] == ' ')
			continue;
	}
	return true;
}

static bool operation(std::string input, std::stack<int> &pile )
{
	size_t start = 0, end = 0;
	int n = 0, nb1 = 0, nb2 = 0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (isspace(input[i]))
			continue;

		if (isdigit(input[i]))
		{
			start = i;
			while (isdigit(input[i]) && (i < input.length()))
				i++;
			end = i;
			n = atoi((input.substr(start, end - start)).c_str());
			if (n > 10 || n < 0)
				return false;
			pile.push(n);
		}
		else if (is_operator(input[i]))
		{
			if (pile.size() < 2)
				return false;
			nb1 = pile.top();
			pile.pop();
			nb2 = pile.top();
			pile.pop();
			if (nb1 == 0 && input[i] == '/')
				return false;
			pile.push(do_operation(nb2, nb1, input[i]));
			
		}
		else
			return false;
	}
	if (pile.size() != 1)
		return false;
	
	return true;
}

void RPN::displayResult(void)
{
	std::stack<int> pile;

	if (!verif_input(_input))
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	else if (!operation(_input, pile))
	{
		std::cerr << "Error" << std::endl;
		return;
	}
	else
		std::cout << pile.top() << std::endl;
}
