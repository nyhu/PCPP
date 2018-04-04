#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Base.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "generating obj A" << std::endl;
		return new A;
	case 1:
		std::cout << "generating obj B" << std::endl;
		return new B;
	case 2:
		std::cout << "generating obj C" << std::endl;
		return new C;
	}
	return NULL;
}

void identify_from_pointer(Base *p)
{
	A *a;
	B *b;
	C *c;

	if ((a = dynamic_cast<A *>(p)))
		std::cout << "ptr match with A" << std::endl;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "ptr match with B" << std::endl;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "ptr match with C" << std::endl;
}

void identify_from_reference(Base &r)
{
	A *a;
	B *b;
	C *c;

	if ((a = dynamic_cast<A *>(&r)))
		std::cout << "ref match with A" << std::endl;
	if ((b = dynamic_cast<B *>(&r)))
		std::cout << "ref match with B" << std::endl;
	if ((c = dynamic_cast<C *>(&r)))
		std::cout << "ref match with C" << std::endl;
}

int main(void)
{
	srand(std::time(NULL));

	Base *id = generate();

	identify_from_pointer(id);
	identify_from_reference(*id);

	return (0);
}
