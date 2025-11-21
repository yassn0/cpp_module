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
	void fordJohnsonDeque(std::deque<int> &deq);

	void binaryInsertVector(std::vector<int> &vec, int value);
	void binaryInsertDeque(std::deque<int> &deq, int value);

	std::vector<size_t> generateJacobsthalSequence(size_t n);
	std::vector<size_t> generateInsertionOrder(size_t n);
};
