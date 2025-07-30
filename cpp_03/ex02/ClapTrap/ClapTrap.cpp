#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad) : _name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << "ClapTrap Constructor called, hp, ep, ad initialize " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_ad = other._ad;
		this->_hp = other._hp;
		this->_ep = other._ep;
	}
	std::cout << "= operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_ad << " points of damage!" << std::endl;
		this->_ep -= 1;
	}
	else
		std::cout <<"ClipTrap " << this->_name << " can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp < 0)
	{
		std::cout << _name << " already died!" << std::endl;
		return;
	}
	std::cout << this->_name << " take " << amount << " points of damage!" << std::endl;
	this->_hp -= amount;
	if (_hp < 0)
		std::cout << _name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep > 0 && this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " reapair " << amount << " hp!" << std::endl;
		this->_ep -= 1;
		this->_hp += amount;
	}
	else
		std::cout << this->_name << " can't attack" << std::endl;
}
