#include <iostream>
#include <string>
#include "ClapTrap/ClapTrap.hpp"

int main()
{
	ClapTrap player1("Bob");
	player1.attack("Stormtrooper");

	ClapTrap copy(player1);
	copy.attack("Imperial");

	ClapTrap player2("C3PO");
	player2 = player1;
	player2.attack("Sith");

	ClapTrap player3;
	return 0;
}