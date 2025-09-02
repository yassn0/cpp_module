#include "Zombie.h"

int	main()
{
	const int N = 10;
	int i = 0;
	
	Zombie *zombies = zombieHorde(N, "BOB");
	if (!zombies)
		return 1;
	while (i < N)
	{
		zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return 0;	
}