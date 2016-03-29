#ifndef HEADER
#define HEADER
#include <iostream>
#include <fstream>

const int foobar = 322;


static double neshto = 27.5;


struct shitDataStruct
{
	char* str;
	int foo;
	double bar;
};

struct plainDataStruct
{
	char str[255];
	int foo;
	double bar;
};

// предаването на аргументите по псевдоним е, защото 
// всеки от тях ще бъде променян 
bool readInput(std::ifstream& input, plainDataStruct*& pArr, int& Count);

#endif // !HEADER

