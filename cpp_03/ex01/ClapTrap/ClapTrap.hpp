#pragma once

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	ClapTrap(std::string name, int hp, int ep, int ad);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string _name;
	int _hp;
	int _ep;
	int _ad;

private:
	ClapTrap();
};

#endif