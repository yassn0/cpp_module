#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain &);
	Brain &operator=(const Brain &);

private:
	std::string ideas[100];
};

#endif