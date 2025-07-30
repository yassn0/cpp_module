#include "ScavTrap/ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap b("Cody");

	b.beRepaired(3);
	b.attack("test");
	b.beRepaired(3);
	return (0);
}
