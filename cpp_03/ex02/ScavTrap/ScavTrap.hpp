#pragma once

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &);

	void guardGate(void);
	void attack(const std::string &target);

private:
	ScavTrap();
	bool _guard;
};

#endif