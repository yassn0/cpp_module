#include "PmergeMe_class/PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	PmergeMe algo;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	if (!algo.check(ac, av))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	algo.sortVector();
	// algo.sortDeque();
	return 0;
}