#pragma once

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"
#include <string>

class FlagTrap : public ClapTrap
{
public:
	FlagTrap(std::string name);
	~FlagTrap();
	FlagTrap(const FlagTrap &other);
	FlagTrap &operator=(const FlagTrap &);

	void guardGate(void);
	void attack(const std::string &target);
	void highFivesGuys(void);

private:
	FlagTrap();
	bool _guard;
};

#endif