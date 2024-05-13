#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>

Base *generate(void)
{
	int rand = std::rand() % 3;

	if (rand == 0)
		return new A;
	else if (rand == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) { }
}

int	main(void)
{
	std::srand(std::time(0));
	Base *base = generate();

	std::cout << "identify(base *p): ";
	identify(base);
	std::cout << "identify(base &p): ";
	identify(*base);
	delete base;

	return 0;
}