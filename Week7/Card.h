#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card
{
private:
	char* name;
	int id;
public:
	Card();
	Card(const Card&);
	Card& operator=(const Card&);
	~Card();

public:
	const char* getName() const;
	void setName(const char*);

	int getId() const;
	//void setId(int);

private:
	void copyElems(const Card&);
};



#endif // !CARD_H

