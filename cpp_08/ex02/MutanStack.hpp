#pragma once

#include <deque>
#include <iostream>
#include <cstdlib>

template <class T, class Container = std::deque<T> >
class MutantStack
{
public:
	
	typedef T value_type;
	typedef Container container_type;
	typedef std::size_t size_type;

	MutantStack() : _cont(Container())
	{
		std::cout << "MutanStack Constructor called" << std::endl;
	}
	~MutantStack()
	{
	}
	MutantStack(const MutantStack &copy) : _cont(copy._cont)
	{
		std::cout << "MutanStack Copy Constructor called" << std::endl;
	}
	MutantStack &operator=(const MutantStack &obj)
	{
		_cont = obj._cont;
		std::cout << "operator= MutanStack called" << std::endl;
		return *this;
	}
	
	

private:
	Container _cont;
};