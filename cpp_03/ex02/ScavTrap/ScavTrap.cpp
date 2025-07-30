#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20), _guard(false)
{
	std::cout << "Scav Trap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Trap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), _guard(other._guard)
{
	std::cout << "Scav Trap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "= operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't attack" << std::endl;
}

void ScavTrap::guardGate(void)
{
	_guard = true;
	std::cout << "ScavTrap " << _name << " Gate keeper mode" << std::endl;
}
