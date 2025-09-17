#pragma once

#include <string>

class RPN
{
public:
	RPN(std::string input);
	~RPN();
	RPN(const RPN &);
	RPN &operator=(const RPN &);

	void	displayResult(void);
private:
	std::string _input;
	RPN();
};
