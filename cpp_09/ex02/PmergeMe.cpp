#include "PmergeMe.hpp"
#include <algorithm>
#include <map>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}





void PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	fordJohnsonVector(vec);
}

void PmergeMe::fordJohnsonVector(std::vector<int> &vec)
{
	// Step 1: Group elements into pairs and sort each pair
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	// Handle odd element if exists
	int straggler = -1;
	bool has_straggler = false;
	if (i < vec.size())
	{
		straggler = vec[i];
		has_straggler = true;
	}

	// Step 2: Create a map to maintain association between larger and smaller
	std::map<int, int> large_to_small;
	for (size_t j = 0; j < pairs.size(); j++)
		large_to_small[pairs[j].first] = pairs[j].second;

	// Step 3: Sort pairs by their larger element (recursive)
	std::vector<int> larger_elements;
	for (size_t j = 0; j < pairs.size(); j++)
		larger_elements.push_back(pairs[j].first);

	if (larger_elements.size() > 1)
		fordJohnsonVector(larger_elements);

	// Step 4: Build main chain with larger elements
	std::vector<int> main_chain;
	for (size_t j = 0; j < larger_elements.size(); j++)
		main_chain.push_back(larger_elements[j]);

	// Step 5: Insert smaller elements using binary insertion
	std::vector<int> smaller_elements;
	for (size_t j = 0; j < larger_elements.size(); j++)
		smaller_elements.push_back(large_to_small[larger_elements[j]]);

	// Insert the first smaller element at the beginning
	if (smaller_elements.size() > 0)
	{
		main_chain.insert(main_chain.begin(), smaller_elements[0]);
	}

	// Insert remaining smaller elements using binary insertion
	for (size_t j = 1; j < smaller_elements.size(); j++)
		binaryInsertVector(main_chain, smaller_elements[j]);

	// Insert straggler if exists
	if (has_straggler)
		binaryInsertVector(main_chain, straggler);

	// Copy result back to vec
	vec = main_chain;
}

void PmergeMe::binaryInsertVector(std::vector<int> &vec, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), value);
	vec.insert(pos, value);
}

// ============================================================================
// DEQUE IMPLEMENTATION
// ============================================================================

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	fordJohnsonDeque(deq);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
	// Step 1: Group elements into pairs and sort each pair
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	// Handle odd element if exists
	int straggler = -1;
	bool has_straggler = false;
	if (i < deq.size())
	{
		straggler = deq[i];
		has_straggler = true;
	}

	// Step 2: Create a map to maintain association
	std::map<int, int> large_to_small;
	for (size_t j = 0; j < pairs.size(); j++)
		large_to_small[pairs[j].first] = pairs[j].second;

	// Step 3: Sort pairs by their larger element (recursive)
	std::deque<int> larger_elements;
	for (size_t j = 0; j < pairs.size(); j++)
		larger_elements.push_back(pairs[j].first);

	if (larger_elements.size() > 1)
		fordJohnsonDeque(larger_elements);

	// Step 4: Build main chain with larger elements
	std::deque<int> main_chain;
	for (size_t j = 0; j < larger_elements.size(); j++)
		main_chain.push_back(larger_elements[j]);

	// Step 5: Insert smaller elements using binary insertion
	std::vector<int> smaller_elements;
	for (size_t j = 0; j < larger_elements.size(); j++)
		smaller_elements.push_back(large_to_small[larger_elements[j]]);

	// Insert the first smaller element at the beginning
	if (smaller_elements.size() > 0)
	{
		main_chain.push_front(smaller_elements[0]);
	}

	// Insert remaining smaller elements using binary insertion
	for (size_t j = 1; j < smaller_elements.size(); j++)
		binaryInsertDeque(main_chain, smaller_elements[j]);

	// Insert straggler if exists
	if (has_straggler)
		binaryInsertDeque(main_chain, straggler);

	// Copy result back to deq
	deq = main_chain;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &deq, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), value);
	deq.insert(pos, value);
}
