#include "../Zombie.h"

Zombie::Zombie() : name("default")
{
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " died" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name << ": "
		    << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &str)
{
	this->name = str;
}