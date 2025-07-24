#include "Weapon.hpp"

Weapon::Weapon(std::string str) : _type(str)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(std::string str)
{
	this->_type = str;
}
