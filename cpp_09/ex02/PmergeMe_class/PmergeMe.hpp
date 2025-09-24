#pragma once

#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cstddef>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);

	bool check(int ac, char **av);
	void sortVector();
	void sortDeque();
	
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
};
