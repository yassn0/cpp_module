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

// Generate Jacobsthal numbers: J(n) = J(n-1) + 2*J(n-2), with J(0)=0, J(1)=1
// Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171...
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return jacobsthal;

	jacobsthal.push_back(0);
	if (n == 1)
		return jacobsthal;

	jacobsthal.push_back(1);

	while (true)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= n)
			break;
		jacobsthal.push_back(next);
	}

	return jacobsthal;
}

// Generate the optimal insertion order based on Jacobsthal sequence
// The order is: J(3), J(3)-1, ..., J(2)+1, J(5), J(5)-1, ..., J(4)+1, etc.
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> jacobsthal = generateJacobsthalSequence(n + 1);

	// Start from index 3 in Jacobsthal sequence (value 3)
	for (size_t i = 3; i < jacobsthal.size(); i++)
	{
		size_t current = jacobsthal[i];
		size_t previous = jacobsthal[i - 1];

		// Insert in descending order from current to previous+1
		for (size_t j = current; j > previous && j <= n; j--)
			order.push_back(j - 1); // -1 because we use 0-based indexing
	}

	// Add any remaining elements
	size_t last_jacob = jacobsthal.size() > 0 ? jacobsthal[jacobsthal.size() - 1] : 0;
	for (size_t i = last_jacob; i < n; i++)
	{
		bool found = false;
		for (size_t j = 0; j < order.size(); j++)
		{
			if (order[j] == i)
			{
				found = true;
				break;
			}
		}
		if (!found)
			order.push_back(i);
	}

	return order;
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

	// Step 5: Insert smaller elements using binary insertion in Jacobsthal order
	std::vector<int> smaller_elements;
	for (size_t j = 0; j < larger_elements.size(); j++)
		smaller_elements.push_back(large_to_small[larger_elements[j]]);

	// Insert the first smaller element at the beginning
	if (smaller_elements.size() > 0)
	{
		main_chain.insert(main_chain.begin(), smaller_elements[0]);
	}

	// Insert remaining smaller elements using Jacobsthal insertion order
	if (smaller_elements.size() > 1)
	{
		std::vector<size_t> insertion_order = generateInsertionOrder(smaller_elements.size());
		for (size_t j = 0; j < insertion_order.size(); j++)
		{
			size_t idx = insertion_order[j];
			if (idx > 0 && idx < smaller_elements.size())
				binaryInsertVector(main_chain, smaller_elements[idx]);
		}
	}

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






void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	fordJohnsonDeque(deq);
}

void PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	int straggler = -1;
	bool has_straggler = false;
	if (i < deq.size())
	{
		straggler = deq[i];
		has_straggler = true;
	}

	std::map<int, int> large_to_small;
	for (size_t j = 0; j < pairs.size(); j++)
		large_to_small[pairs[j].first] = pairs[j].second;

	std::deque<int> larger_elements;
	for (size_t j = 0; j < pairs.size(); j++)
		larger_elements.push_back(pairs[j].first);

	if (larger_elements.size() > 1)
		fordJohnsonDeque(larger_elements);

	std::deque<int> main_chain;
	for (size_t j = 0; j < larger_elements.size(); j++)
		main_chain.push_back(larger_elements[j]);

	std::vector<int> smaller_elements;
	for (size_t j = 0; j < larger_elements.size(); j++)
		smaller_elements.push_back(large_to_small[larger_elements[j]]);

	if (smaller_elements.size() > 0)
		main_chain.push_front(smaller_elements[0]);

	if (smaller_elements.size() > 1)
	{
		std::vector<size_t> insertion_order = generateInsertionOrder(smaller_elements.size());
		for (size_t j = 0; j < insertion_order.size(); j++)
		{
			size_t idx = insertion_order[j];
			if (idx > 0 && idx < smaller_elements.size())
				binaryInsertDeque(main_chain, smaller_elements[idx]);
		}
	}

	if (has_straggler)
		binaryInsertDeque(main_chain, straggler);

	deq = main_chain;
}

void PmergeMe::binaryInsertDeque(std::deque<int> &deq, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), value);
	deq.insert(pos, value);
}
