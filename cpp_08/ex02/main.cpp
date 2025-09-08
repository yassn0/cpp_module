#include "MutanStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <typeinfo>
#include <deque>

// int main()
// {
// 	MutantStack<int> mstack;
// 	MutantStack<int> mstack2(mstack);
// 	MutantStack<int> mstack3;
// 	mstack3 = mstack;

// 	MutantStack<int>::value_type i = 42;
// 	MutantStack<int>::size_type j = 42;
// 	std::deque<int> k;
// 	k.push_back(5);
// 	MutantStack<int>::container_type v = k;

// 	std::cout << i << std::endl;
// 	std::cout << j << std::endl;
// 	std::cout << v.front() << std::endl;

// 	std::deque<int> test;
// 	test.pop_back();
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}