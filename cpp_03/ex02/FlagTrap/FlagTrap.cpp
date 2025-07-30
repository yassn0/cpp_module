#include "FlagTrap.hpp"
#include <iostream>

FlagTrap::FlagTrap(std::string name) : ClapTrap(name, 100, 50, 30), _guard(false)
{
	std::cout << "Flag Trap Constructor called" << std::endl;
}

FlagTrap::~FlagTrap()
{
	std::cout << "Flag Trap Destructor called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other), _guard(other._guard)
{
	std::cout << "Flag Trap Copy constructor called" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

void FlagTrap::attack(const std::string &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "FlagTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "FlagTrap " << this->_name << " can't attack" << std::endl;
}

void FlagTrap::guardGate(void)
{
	_guard = true;
	std::cout << "FlagTrap " << _name << " Gate keeper mode" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
	std::string input;

	std::cout << "High Fives ?  Goo" << std::endl;
}
