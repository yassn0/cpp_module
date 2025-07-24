#include "ScavTrap/ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap b("Cody");

	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	ScavTrap d("Savage");
	d.attack("Savage-clone");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap-clone");
	return (0);
}
