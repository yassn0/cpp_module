#pragma once
#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& cont, int n)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::exception();
	return it;
}