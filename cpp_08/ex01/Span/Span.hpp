#pragma once
#include "cstdlib"
#include <vector>
#include <exception>

class Span
{
public:
	Span(unsigned int N);
	~Span();
	Span(const Span &);
	Span &operator=(const Span &);

	void addNumber(int nb);
	int shortestSpan(void);
	int longestSpan(void);
	
	void	addLotRandomNumber(int i);

	class WrongIndex : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Span can't stored more elements";
		}
	};

private:
	Span();

	std::vector<int> _tab;
	unsigned int _N;
};
