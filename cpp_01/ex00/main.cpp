#include "Zombie.h"

int	main()
{
	Zombie *z = newZombie("foo");
	delete(z);
	
	randomChump("foo2");
}