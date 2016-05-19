#include "Keepo.h"
#include <iostream>

Keepo::Keepo() : Kappa()
{
	nigga = 0;
	std::cout << "Keepo created" << std::endl;
}

Keepo::Keepo(int suka, int blqt, int nigga)
	:Kappa(suka, blqt)
{
	this->nigga = nigga;
	std::cout << "Keepo cool created" << std::endl;
}

Keepo::Keepo(const Keepo& other)
	:Kappa(other)
{
	nigga = other.nigga;

	std::cout << "Keepo copy created" << std::endl;
}

Keepo& Keepo::operator= (const Keepo& other)
{
	std::cout << "Keepo copy" << std::endl;
	if (this != &other)
	{
		Kappa::operator=(other);
		nigga = other.nigga;
	}
	return *this;
}

Keepo::~Keepo()
{
	std::cout << "Keepo killed" << std::endl;
}

void Keepo::print() const
{
	Kappa::print();
	std::cout << nigga << std::endl;
}