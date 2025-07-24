#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;
	
	if (N <= 0)
		return 0;
	Zombie *zombies = new Zombie[N];
	if (!zombies)
		return NULL;
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return zombies;
}