#pragma once

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../Weapon/Weapon.hpp"
#include <iostream>

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void) const;

private:
	std::string _name;
	Weapon &_weapon;
	HumanA();
	HumanA(std::string name);
};

#endif