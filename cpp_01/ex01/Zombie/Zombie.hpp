#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void announce(void) const;
	void setName(const std::string &str);

private:
	std::string name;
};

#endif