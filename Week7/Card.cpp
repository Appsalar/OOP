#include "Card.h"


Card::Card()
{
	name = NULL;
	id = 0;
}

Card::Card(const Card& other)
{
	name = NULL;
	copyElems(other);
}

Card& Card::operator=(const Card& other)
{
	if (this != &other)
		copyElems(other);


	return *this;
}

Card::~Card()
{
	delete[] name;
}

void Card::copyElems(const Card& other)
{
	setName(other.name);

	id = other.id;
}


void Card::setName(const char* name)
{
	delete[] name;
	int size = strlen(name) + 1;
	this->name = new char[size]; //class Card
	strcpy(this->name, name);
}

const char* Card::getName() const
{
	return name;
}

int Card::getId() const
{
	return id;
}