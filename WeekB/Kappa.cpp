#include "Kappa.h"
#include <iostream>

Kappa::Kappa()
{
	suka = 0;
	blqt = 0;

	std::cout << "Kappa created" << std::endl;
}

Kappa::Kappa(int suka, int blqt)
{
	this->suka = suka;
	this->blqt = blqt;
	std::cout << "Kappa cool created" << std::endl;
}

Kappa::Kappa(const Kappa& other)
{
	this->suka = other.suka;
	this->blqt = other.blqt;
	std::cout << "Kappa copy created" << std::endl;
}

Kappa& Kappa::operator= (const Kappa& other)
{
	std::cout << "Kappa copy" << std::endl;
	if (this != &other)
	{
		suka = other.suka;
		blqt = other.blqt;
	}
	return *this;
}

Kappa::~Kappa()
{
	std::cout << "Kappa killed" << std::endl;
}

void Kappa::print() const
{
	std::cout << suka << std::endl
			<< blqt << std::endl;
}
