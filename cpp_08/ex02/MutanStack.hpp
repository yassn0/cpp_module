#pragma once

#include <deque>
#include <iostream>
#include <cstdlib>
#include <list>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef T value_type;
	typedef Container container_type;
	typedef std::size_t size_type;

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }

	MutantStack() : std::stack<T, Container>()
	{
		std::cout << "MutanStack Constructor called" << std::endl;
	}
	~MutantStack()
	{
	}
	MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy)
	{
		std::cout << "MutanStack Copy Constructor called" << std::endl;
	}
	MutantStack &operator=(const MutantStack &obj)
	{
		std::stack<T, Container>::operator=(obj);
		std::cout << "operator= MutanStack called" << std::endl;
		return *this;
	}

private:
};