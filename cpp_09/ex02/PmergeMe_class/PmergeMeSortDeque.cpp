#include "PmergeMe.hpp"

static void make_pairs_deque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &deque)
{
	for (size_t i = 0; i < deque.size(); i = i + 2)
	{
		pairs.push_back(std::pair<int, int>(deque[i], deque[i + 1]));
	}
}

static void sort_pairs_deque(std::deque<std::pair<int, int> > &pairs)
{
	int tmp;

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->second > it->first)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

static void recursiveMergeSortDeque(std::deque<std::pair<int, int> > &pairs)
{
	// Cas de base : si 0 ou 1 paire, déjà trié
	if (pairs.size() <= 1)
		return;

	// Étape 1: Créer des paires de paires (grouper par 2) - IDENTIQUE à vector
	std::deque<std::pair<int, int> > maxs;   // Les éléments maximaux de chaque groupe
	std::deque<std::pair<int, int> > mins;   // Les éléments minimaux correspondants
	std::pair<int, int> straggler;           // Paire impaire s'il y en a une
	bool has_straggler = false;

	// Grouper les paires par 2 et déterminer les gagnants/perdants - IDENTIQUE
	for (size_t i = 0; i + 1 < pairs.size(); i += 2)
	{
		if (pairs[i].first > pairs[i + 1].first)
		{
			maxs.push_back(pairs[i]);    // pairs[i] gagne
			mins.push_back(pairs[i + 1]); // pairs[i+1] perd
		}
		else
		{
			maxs.push_back(pairs[i + 1]); // pairs[i+1] gagne
			mins.push_back(pairs[i]);      // pairs[i] perd
		}
	}

	// Gérer la paire impaire - IDENTIQUE
	if (pairs.size() % 2 != 0)
	{
		straggler = pairs[pairs.size() - 1];
		has_straggler = true;
	}

	// Étape 2: Trier récursivement les gagnants - IDENTIQUE
	recursiveMergeSortDeque(maxs);

	// Étape 3: Reconstruire le résultat - MÊME LOGIQUE que vector
	pairs.clear();

	// Ajouter le premier perdant et le premier gagnant - IDENTIQUE
	if (!maxs.empty() && !mins.empty())
	{
		pairs.push_back(mins[0]);
		pairs.push_back(maxs[0]);
	}

	// Ajouter le reste des gagnants - IDENTIQUE
	for (size_t i = 1; i < maxs.size(); ++i)
		pairs.push_back(maxs[i]);

	// Créer un vecteur temporaire pour les insertions efficaces
	std::vector<std::pair<int, int> > temp_vec(pairs.begin(), pairs.end());

	// Insérer les perdants restants avec vector (plus efficace)
	for (size_t i = 1; i < mins.size(); ++i)
	{
		// Recherche binaire manuelle
		size_t left = 0, right = temp_vec.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (temp_vec[mid].first < mins[i].first)
				left = mid + 1;
			else
				right = mid;
		}
		temp_vec.insert(temp_vec.begin() + left, mins[i]);
	}

	// Ajouter la paire impaire
	if (has_straggler)
	{
		size_t left = 0, right = temp_vec.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (temp_vec[mid].first < straggler.first)
				left = mid + 1;
			else
				right = mid;
		}
		temp_vec.insert(temp_vec.begin() + left, straggler);
	}

	// Remettre dans le deque
	pairs.clear();
	for (size_t i = 0; i < temp_vec.size(); ++i)
		pairs.push_back(temp_vec[i]);
}

static void sortMainChainDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &deque, std::deque<int> &pending)
{
	// Utiliser la MÊME récursion Ford-Johnson que vector
	recursiveMergeSortDeque(pairs);

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it == pairs.begin())
		{
			deque.push_back(it->second);
			deque.push_back(it->first);
		}
		else
		{
			deque.push_back(it->first);
			pending.push_back(it->second);
		}
	}
}

static std::deque<size_t> generateJacobsthalSequenceDeque(size_t size_pending)
{
	std::deque<size_t> jacobsthal;

	if (size_pending == 0)
		return jacobsthal;
	jacobsthal.push_back(1);
	if (size_pending == 1)
		return jacobsthal;
	jacobsthal.push_back(1);
	while (true)
	{
		size_t next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > size_pending)
			break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

static void insertPendingWithJacobsthalDeque(std::deque<int> &main_chain, std::deque<int> &pending, int last_element)
{
	if (pending.empty())
	{
		if (last_element != -1)
		{
			std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), last_element);
			main_chain.insert(pos, last_element);
		}
		return;
	}

	std::deque<size_t> jacobsthal = generateJacobsthalSequenceDeque(pending.size());
	std::deque<size_t> insertion_order;

	insertion_order.push_back(0);

	size_t last_index = 1;

	for (size_t i = 2; i < jacobsthal.size(); ++i)
	{
		size_t current_jacobsthal = jacobsthal[i];
		for (size_t j = std::min(current_jacobsthal - 1, pending.size() - 1); j >= last_index && j < pending.size(); --j)
		{
			insertion_order.push_back(j);
			if (j == 0)
				break;
		}

		last_index = current_jacobsthal;
	}

	for (size_t i = last_index; i < pending.size(); ++i)
		insertion_order.push_back(i);

	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		size_t idx = insertion_order[i];
		std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending[idx]);
		main_chain.insert(pos, pending[idx]);
	}

	if (last_element != -1)
	{
		std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), last_element);
		main_chain.insert(pos, last_element);
	}
}

void PmergeMe::sortDeque()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	int last_element = -1;
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> pending;

	if (_deque.size() % 2 != 0)
	{
		last_element = _deque.back();
		_deque.pop_back();
	}

	make_pairs_deque(pairs, _deque);
	sort_pairs_deque(pairs);
	_deque.clear();
	sortMainChainDeque(pairs, _deque, pending);
	insertPendingWithJacobsthalDeque(_deque, pending, last_element);

	gettimeofday(&end, NULL);
	_deque_time = getTimeDiff(start, end);
}