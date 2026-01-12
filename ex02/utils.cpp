#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

enum {A_CLASS, B_CLASS, C_CLASS};

Base* generate(void)
{
	int randomNum = rand() % 3;
	Base* base = NULL;

	switch (randomNum)
	{
		case A_CLASS:
			base = new A();
			break ;
		case B_CLASS:
			base = new B();
			break ;
		case C_CLASS:
			base = new C();
	}
	return base;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "ptr p is from class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "ptr p is from class B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "ptr p is from class C\n";
	else
		std::cout << "Error: object unidentified\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "ref p is from class A\n";
		return ;
	} catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "ref p is from class B\n";
		return ;
	} catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "ref p is from class C\n";
		return ;
	} catch (...) {}
	std::cout << "Error: object unidentified\n";
}
