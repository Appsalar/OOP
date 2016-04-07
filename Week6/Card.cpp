#include "Card.h"


Card::Card()
{
	name = NULL;
	id = 0;
}

Card::Card(const Card& other)
{
	int size = strlen(other.name) + 1;
	name = new char[size];
	strcpy(name, other.name);

	id = other.id;
}

Card::~Card()
{
	delete[] name;
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