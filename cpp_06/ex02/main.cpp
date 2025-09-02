#include "Base/Base.hpp"
#include "ABC/ABC.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
	{
		return new A;
	}
	else if (random == 1)
	{
		return new B;
	}
	else
	{
		return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "C" << std::endl;
	else
		std::cout << "???" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &bc1)
	{
		static_cast<void>(bc1);
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &bc2)
	{
		static_cast<void>(bc2);
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception &bc3)
	{
		static_cast<void>(bc3);
	}
}

int main()
{
	std::srand(std::time(0));

	Base *instance1 = generate();
	identify(instance1);
	Base &ref_instance1 = *instance1;
	identify(ref_instance1);
}