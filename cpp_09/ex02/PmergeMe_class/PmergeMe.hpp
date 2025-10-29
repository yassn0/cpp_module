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
#include <sys/time.h>

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
	void printResults();

private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	double _vector_time;
	double _deque_time;

	double getTimeDiff(struct timeval start, struct timeval end);
};
