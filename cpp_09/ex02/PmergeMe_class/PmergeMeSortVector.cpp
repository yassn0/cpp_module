#include "PmergeMe.hpp"

static void printInt(int x)
{
	std::cout << x << " ";
}

static void printPairs(std::pair<int, int> v_pairs)
{
	std::cout << "(" << v_pairs.first << "," << v_pairs.second << ") ";
}

static void make_pairs(std::vector<std::pair<int, int> > &v_pairs, std::vector<int> &vector)
{
	for (size_t i = 0; i < vector.size(); i = i + 2)
	{
		v_pairs.push_back(std::pair<int, int>(vector[i], vector[i + 1]));
	}
	for_each(v_pairs.begin(), v_pairs.end(), printPairs);
	std::cout << std::endl;
	
}

static void sort_pairs(std::vector<std::pair<int, int> > &v_pairs)
{
	int tmp;
	
	for (std::vector<std::pair<int, int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); ++it)
	{
		if (it->second > it->first)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

static void sortMainChain(std::vector<std::pair<int, int> > &v_pairs, std::vector<int> &vector)
{
	for (std::vector<std::pair<int, int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); ++it)
		vector.push_back(it->first);
	//...
}

void PmergeMe::sortVector()
{
	int last_element = -1;
	std::vector<std::pair<int, int> > v_pairs;
	
	if (_vector.size() % 2 != 0)
	{
		last_element = _vector.back();
		_vector.pop_back();
		std::cout << last_element << std::endl;
	}
	make_pairs(v_pairs, _vector); //step 1
	sort_pairs(v_pairs); //step 2
	_vector.clear();
	sortMainChain(v_pairs, _vector); //step3
	
	for_each(v_pairs.begin(), v_pairs.end(), printPairs);
	std::cout << std::endl;
	for_each(_vector.begin(), _vector.end(), printInt);
}