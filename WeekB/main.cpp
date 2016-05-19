#include <iostream>
#include "Kappa.h"
#include "Keepo.h"

int main()
{
	Kappa foo(42, 420);
	Kappa bar;
	foo.print();

	std::cout << "----------------------" << std::endl;

	Keepo a;
	Keepo b(322, 1337, 420);
	b.print();

	std::cout << "----------------------" << std::endl;

	a = b;
	a.print();

	std::cout << "----------------------" << std::endl;

	Kappa nigger(foo);
	nigger.print();

	std::cout << "----------------------" << std::endl;

	Kappa* rekt = new Keepo(13, 42, 322);

	rekt->print();
	delete rekt;

	std::cout << "----------------------" << std::endl;

	return 0;
}