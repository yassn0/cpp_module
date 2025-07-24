#include "Zombie.h"

int	main()
{
	const int N = 10;
	int i = 0;
	
	Zombie *zombies = zombieHorde(N, "BOB");
	if (!zombies)
		return NULL;
	while (i < N)
	{
		zombies[i].announce();
		i++;
	}
	i = 0;
	delete [] zombies;	
}