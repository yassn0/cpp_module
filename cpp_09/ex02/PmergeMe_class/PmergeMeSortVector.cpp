#include "PmergeMe.hpp"

static void make_pairs(std::vector<std::pair<int, int> > &pairs, std::vector<int> &vector)
{
	for (size_t i = 0; i < vector.size(); i = i + 2)
	{
		pairs.push_back(std::pair<int, int>(vector[i], vector[i + 1]));
	}
}

static void sort_pairs(std::vector<std::pair<int, int> > &pairs)
{
	int tmp;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->second > it->first)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

static void recursiveMergeSort(std::vector<std::pair<int, int> > &pairs)
{
	// Cas de base : si 0 ou 1 paire, déjà trié
	if (pairs.size() <= 1)
		return;

	// Étape 1: Créer des paires de paires (grouper par 2)
	std::vector<std::pair<int, int> > maxs;   // Les éléments maximaux de chaque groupe
	std::vector<std::pair<int, int> > mins;    // Les éléments minimaux correspondants
	std::pair<int, int> straggler;               // Paire impaire s'il y en a une
	bool has_straggler = false;

	// Grouper les paires par 2 et déterminer les gagnants/perdants
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

	// Gérer la paire impaire
	if (pairs.size() % 2 != 0)
	{
		straggler = pairs[pairs.size() - 1];
		has_straggler = true;
	}

	// Étape 2: Trier récursivement les gagnants
	recursiveMergeSort(maxs);

	// Étape 3: Reconstruire le résultat
	// Les gagnants sont maintenant triés, on reconstruit avec leurs perdants correspondants
	pairs.clear();

	// Ajouter le premier perdant et le premier gagnant
	if (!maxs.empty() && !mins.empty())
	{
		pairs.push_back(mins[0]);
		pairs.push_back(maxs[0]);
	}

	// Ajouter le reste des gagnants
	for (size_t i = 1; i < maxs.size(); ++i)
		pairs.push_back(maxs[i]);

	// Créer un vecteur temporaire pour les insertions efficaces - IDENTIQUE à deque
	std::vector<std::pair<int, int> > temp_vec(pairs.begin(), pairs.end());

	// Insérer les perdants restants avec vector - IDENTIQUE à deque
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

	// Ajouter la paire impaire - IDENTIQUE à deque
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

	// Remettre dans le vector - IDENTIQUE à deque
	pairs.clear();
	for (size_t i = 0; i < temp_vec.size(); ++i)
		pairs.push_back(temp_vec[i]);
}

static void sortMainChain(std::vector<std::pair<int, int> > &pairs, std::vector<int> &vector, std::vector<int> &pending)
{
	recursiveMergeSort(pairs);

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it == pairs.begin())
		{
			vector.push_back(it->second);
			vector.push_back(it->first);
		}
		else
		{
			vector.push_back(it->first);
			pending.push_back(it->second);
		}
	}
}

static std::vector<size_t> generateJacobsthalSequence(size_t size_pending)
{
	std::vector<size_t> jacobsthal;

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

static void insertPendingWithJacobsthal(std::vector<int> &main_chain, std::vector<int> &pending, int last_element)
{
	if (pending.empty())
	{
		if (last_element != -1)
		{
			std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), last_element);
			main_chain.insert(pos, last_element);
		}
		return;
	}
	std::vector<size_t> jacobsthal = generateJacobsthalSequence(pending.size());
	std::vector<size_t> insertion_order;

	
	insertion_order.push_back(0); // Toujours insérer le premier élément (index 0)

	// Pour chaque nombre de Jacobsthal, insérer les éléments dans l'ordre décroissant
	size_t last_index = 1; // On a déjà traité l'index 0

	for (size_t i = 2; i < jacobsthal.size(); ++i) // Commencer à i=2 car jacobsthal[1]=1
	{
		size_t current_jacobsthal = jacobsthal[i];
		// Insérer de current_jacobsthal-1 jusqu'à last_index (ordre décroissant)
		for (size_t j = std::min(current_jacobsthal - 1, pending.size() - 1); j >= last_index && j < pending.size(); --j)
		{
			insertion_order.push_back(j);
			if (j == 0)
				break;
		}

		last_index = current_jacobsthal;
	}

	// Ajouter les éléments restants s'il y en a
	for (size_t i = last_index; i < pending.size(); ++i)
		insertion_order.push_back(i);

	// Effectuer l'insertion dans l'ordre calculé
	for (size_t i = 0; i < insertion_order.size(); ++i)
	{
		size_t idx = insertion_order[i];
		std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending[idx]);
		main_chain.insert(pos, pending[idx]);
	}

	// Insérer l'élément impair s'il existe
	if (last_element != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), last_element);
		main_chain.insert(pos, last_element);
	}
}

void PmergeMe::sortVector()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	int last_element = -1;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> pending;

	if (_vector.size() % 2 != 0)
	{
		last_element = _vector.back();
		_vector.pop_back();
	}

	make_pairs(pairs, _vector); // step 1
	sort_pairs(pairs); // step 2
	_vector.clear();
	sortMainChain(pairs, _vector, pending); // step3 : trier les max puis les push dans la mainchain
	insertPendingWithJacobsthal(_vector, pending, last_element); // step4 : insertion avec Jacobsthal

	gettimeofday(&end, NULL);
	_vector_time = getTimeDiff(start, end);
	
}