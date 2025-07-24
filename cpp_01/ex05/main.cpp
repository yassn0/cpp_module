#include "Harl/Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	(void)av;
	
	if (ac != 1)
		return (1);

	harl.complain("DEBUG");
}