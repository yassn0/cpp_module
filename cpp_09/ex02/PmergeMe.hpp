#pragma once

#include <vector>
#include <deque>
#include <string>
#include <map>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void sortVector(std::vector<int> &vec);
	void sortDeque(std::deque<int> &deq);

private:
	void fordJohnsonVector(std::vector<int> &vec);
	void insertionSortVector(std::vector<int> &vec);

	void fordJohnsonDeque(std::deque<int> &deq);
	void insertionSortDeque(std::deque<int> &deq);

	std::vector<int> mergeVector(std::vector<int> &left, std::vector<int> &right);
	void binaryInsertVector(std::vector<int> &vec, int value);

	std::deque<int> mergeDeque(std::deque<int> &left, std::deque<int> &right);
	void binaryInsertDeque(std::deque<int> &deq, int value);
};
