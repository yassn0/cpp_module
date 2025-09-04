#pragma once
#include <exception>

template<typename T>
bool easyfind(T cont, int n){
	for (typename T::iterator it = cont.begin() ; it != cont.end(); ++it)
	{
		if (*it == n)
			return true;
	}
	return false;
}