#include "../Zombie.h"

Zombie::Zombie(std::string zombie_name) : name(zombie_name)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " died" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": "
	<< "BraiiiiiiinnnzzzZ..." << std::endl;
}