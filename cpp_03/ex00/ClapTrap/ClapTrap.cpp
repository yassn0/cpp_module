#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->ad = other.ad;
		this->hp = other.hp;
		this->ep = other.ep;
	}
	return *this;
}
